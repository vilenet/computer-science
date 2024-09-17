// LeetCode
// 724. Find Pivot Index
//
// The pivot index is the index where the sum of all the 
// numbers strictly to the left of the index is equal to 
// the sum of all the numbers strictly to the index's right.

#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int totalSum = 0;
    for (int n : nums) {
        totalSum += n;
    }

    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        } 
        leftSum += nums[i];
    }

    return -1;
}

int main()
{
    vector<int> nums1 = {1,7,3,6,5,6};
    cout << pivotIndex(nums1) << endl; // 3

    vector<int> nums2 = {1,2,3};
    cout << pivotIndex(nums2) << endl; // -1

    vector<int> nums3 = {2,1,-1};
    cout << pivotIndex(nums3) << endl; // 0

    return 0;
}