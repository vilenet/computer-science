/*
LeetCode
1. Two Sum

Given an array of integers nums and an integer target, 
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 
Follow-up: Can you come up with an algorithm that is 
less than O(n2) time complexity?
*/
#include <unordered_map>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> numMap;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }

        numMap[nums[i]] = i;
    }

    return vector<int>();
}

int main()
{
    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> expect1 = {0, 1};
    assert(twoSum(nums1, 9) == expect1);

    vector<int> nums2 = {3, 2, 4};
    vector<int> expect2 = {1, 2};
    assert(twoSum(nums2, 6) == expect2);

    vector<int> nums3 = {3, 3};
    vector<int> expect3 = {0, 1};
    assert(twoSum(nums3, 6) == expect3);

    return 0;
}