// Example 1: Find the number of subarrays whose sum is equal to target
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int countSubArray(vector<int>& nums, int target) {
    unordered_map<int, int> prefixSumCount;
    prefixSumCount[0] = 1;
    int currSum = 0;
    int count = 0;

    for (const int& n : nums) {
        currSum += n;

        if (prefixSumCount.find(currSum - target) != prefixSumCount.end()) {
            count += prefixSumCount[currSum - target];
        }

        prefixSumCount[currSum]++;
    }

    return count;
}

int main()
{
    vector<int> arr = {1, 2, 3, -1, 2};
    int target = 4;
    cout << "Number of subarrays with sum " << target << " is: " 
         << countSubArray(arr, target) << endl;
    return 0;
}