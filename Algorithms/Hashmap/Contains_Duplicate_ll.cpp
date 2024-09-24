/*
LeetCode
219. Contains Duplicate II

Given an integer array nums and an integer k, return true if there are two 
distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 
Example 1:
Input: nums = [1,2,3,1], k = 3
Output: true

Example 2:
Input: nums = [1,0,1,1], k = 1
Output: true

Example 3:
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
 
Constraints:

1 <= nums.length <= 105
-109 <= nums[i] <= 109
0 <= k <= 105
*/
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>
using namespace std;

bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_map<int, int> numIndex;

    for (int i = 0; i < nums.size(); ++i) {
        if (numIndex.find(nums[i]) != numIndex.end() && i - numIndex[nums[i]] <= k) {
            return true;
        }
        numIndex[nums[i]] = i;
    } 

    return false;
}

int main()
{
    assert(containsNearbyDuplicate({1,2,3,1}, 3) == true);
    assert(containsNearbyDuplicate({1,0,1,1}, 1) == true);
    assert(containsNearbyDuplicate({1,2,3,1,2,3}, 2) == false);

    return 0;
}