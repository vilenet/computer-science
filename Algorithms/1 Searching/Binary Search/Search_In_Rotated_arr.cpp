// Search in Rotated Sorted Array
#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) return mid;

        if (nums[left] <= nums[mid]) { // Left part is sorted
            if (nums[left] <= target && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else { // Right side is sorted
            if (nums[mid] < target && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }

    return -1;
}

int main() 
{
    std::vector<int> nums = { 4, 5, 6, 7, 0, 1, 2 };
    int target = 7;
    int result = search(nums, target);
    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}