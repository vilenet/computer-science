#include <vector>
#include <iostream>

int peakIndexInMountainArray(std::vector<int>& arr) {
    int left = 0;
    int right = arr.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }

    }

    return left;
}

int main()
{
    std::vector<int> arr = { 0, 2, 4, 7, 5, 3, 1 };
    int peakIndex = peakIndexInMountainArray(arr);
    std::cout << "Peak index is: " << peakIndex << std::endl;
    return 0;
}