// Rotate Vector Array by k times
#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<int>& nums, int k){
    int n = nums.size();
    if (n <= 1 || k == 0) return;
    k = k % n;

    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k);
    std::reverse(nums.begin() + k, nums.end());
}

int main() 
{
    std::vector<int> nums = {1, 2, 3, 4, 5};
    
    rotate(nums, 4);

    for (int i : nums) {
        std::cout << i << " ";
    }

    return 0;
}