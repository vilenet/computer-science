// Product of Array Except Self
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    if (nums.empty()) return {};
    int n = nums.size();
    vector<int> result(n, 1);

    int product = 1;
    for (int i = 0; i < n; i++) {
        result[i] = result[i] * product;
        product   = product * nums[i];
    }

    product = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] = result[i] * product;
        product   = product * nums[i];
    }

    return result;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> expected1 = {24, 12, 8, 6};
    assert(productExceptSelf(nums1) == expected1);

    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> expected2 = {0, 0, 9, 0, 0};
    assert(productExceptSelf(nums2) == expected2);

    return 0;
}