// Example 3:  Find the average of the elements of a subarray
#include <iostream>
#include <vector>
using namespace std;

// Function for calculating prefix sums
vector<int> computePrefixSum(const vector<int>& arr) {
    int n = arr.size();
    vector<int> prefixSum(n);
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

// Function to calculate the average of a subarray using prefix sums
double subarrayAverage(const vector<int>& prefixSum, int l, int r) {
    int sum = (l == 0) ? prefixSum[r] : prefixSum[r] - prefixSum[l - 1];
    int count = r - l + 1;
    return (double)sum / count;
}

int main() 
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    vector<int> prefixSum = computePrefixSum(arr);
    
    // Request: find the average value of the subarray from index 2 to 5
    int l = 2, r = 5;
    cout << "Average of arr[" << l << ", " << r << "] is: "
         << subarrayAverage(prefixSum, l, r) << endl;

    return 0;
}
