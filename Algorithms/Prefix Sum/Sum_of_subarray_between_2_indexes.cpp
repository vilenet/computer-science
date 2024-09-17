// Example 2: Find the sum of elements of a subarray between two indexes
#include <iostream>
#include <vector>
using namespace std;

vector<int> computePrefixSum(const vector<int>& arr) {
    vector<int> prefixSum(arr.size());
    prefixSum[0] = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    return prefixSum;
}

int subArrSum(const vector<int>& prefixSum, int l, int  r) {
    return (l == 0) ? prefixSum[r] : prefixSum[r] - prefixSum[l - 1];
}

int main() 
{
    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> prefixSum = computePrefixSum(arr);

    // Request: find the sum of the subarray from index 1 to 3
    int l = 1, r = 3;
    cout << "The sum of the subarray [" << l << ", " << r << "] is "
         << subArrSum(prefixSum, l, r) << endl;
    
    return 0;
}