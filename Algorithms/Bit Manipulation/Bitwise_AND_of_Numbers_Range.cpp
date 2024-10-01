/*
LeetCode
201. Bitwise AND of Numbers Range

Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0

Constraints:
0 <= left <= right <= 231 - 1
*/
#include <iostream>
#include <cassert>
using namespace std;

// O(N)
int rangeBitwiseAnd(int left, int right) {
    int result = left;

    for (int i = left + 1; i <= right; i++) {
        result &= i;
        if (result == 0) break;
    }
    
    return result;
}

// O(log N)
int rangeBitwiseAnd2(int left, int right) {
    int shift = 0;

    while (left != right) {
        left >>= 1;
        right >>= 1;
        shift++;
    }

    return left << shift;
}


int main() 
{
    assert(rangeBitwiseAnd(5, 7) == 4);
    assert(rangeBitwiseAnd(0, 0) == 0);
    assert(rangeBitwiseAnd(1, 2147483647) == 0);

    assert(rangeBitwiseAnd2(5, 7) == 4);
    assert(rangeBitwiseAnd2(0, 0) == 0);
    assert(rangeBitwiseAnd2(1, 2147483647) == 0);

    return 0;
}