/*
LeetCode
202. Happy Number

Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares 
of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops 
endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:
Input: n = 19
Output: true

Explanation:
1*1 + 9*9 = 82
8*8 + 2*2 = 68
6*6 + 8*8 = 100
1*2 + 0*2 + 0*2 = 1

Example 2:
Input: n = 2
Output: false
 
Constraints:

1 <= n <= 231 - 1
*/
#include <unordered_set>
#include <iostream>
#include <cassert>

bool isHappy(int n) {
    std::unordered_set<int> seen;

    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        int sum = 0;

        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        n = sum;
    }

    return n == 1;
}

int main()
{
    assert(isHappy(19) == true);
    assert(isHappy(2) == false);

    return 0;
}