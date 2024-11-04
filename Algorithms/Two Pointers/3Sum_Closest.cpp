// 3Sum Closest
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) { 
    sort(nums.begin(), nums.end()); 

    int sum = nums[0] + nums[1] + nums[2];
    
    for(int i = 0; i < nums.size(); i++) {
        int front = i + 1;
        int back = nums.size() - 1;

        while(front < back) {
            int current_sum = nums[front] + nums[back] + nums[i]; 

            if(abs(current_sum - target) <= abs(sum - target)) { 
                sum = current_sum;
            } 
            if(current_sum > target) { 
                back--; 
            }
            else if(current_sum < target) {
                front++; 
            }
            else {
                return current_sum;
            }
        }
    }

    return sum; 
}

int main()
{
    vector<int> nums1 = {-1, 2, 1, -4};
    assert(threeSumClosest(nums1, 1) == 2);

    vector<int> nums2 = {0, 0, 0};
    assert(threeSumClosest(nums2, 1) == 0);

    return 0;
}