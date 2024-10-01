/*
LeetCode
137. Single Number II

Given an integer array nums where every element appears three times except for 
one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only 
constant extra space.

Example 1: Input: nums = [2,2,3,2].        Output: 3

Example 2: Input: nums = [0,1,0,1,0,1,99]. Output: 99
 
Constraints:
1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1

Each element in nums appears exactly three times except for one element 
which appears once.
*/
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int singleNumber(vector<int>& nums) {
    int bit_count[32] = {0};
    int result = 0;

    for (int num : nums)
        for (int i = 0; i < 32; ++i)
            if (num & (1 << i))
                bit_count[i]++;

    for (int i = 0; i < 32; i++)
        if (bit_count[i] % 3 != 0)
            result |= (1 << i);

    return result;
}

int main() 
{
    std::vector<int> nums1 = {2, 2, 3, 2};
    std::vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};

    assert(singleNumber(nums1) == 3);
    assert(singleNumber(nums2) == 99);

    return 0;
}