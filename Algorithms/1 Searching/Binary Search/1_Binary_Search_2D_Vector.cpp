#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int rows = matrix.size();
    int cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        //Convert linear index to 2D coordinates
        int midValue = matrix[mid / cols][mid % cols];

        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 11;

    if (binarySearch(matrix, target)) {
        cout << target << " is present in the matrix." << endl;
    } else {
        cout << target << " is not present in the matrix." << endl;
    }

    return 0;
}
