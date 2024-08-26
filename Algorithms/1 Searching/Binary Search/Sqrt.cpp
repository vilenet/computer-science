// Implementation of binary search to calculate the square root of a number
#include <iostream>
#include <cassert>

int mySqrt(int x) {
    if (x < 0) return -1;
    if (x == 0 || x == 1) return x;

    int left = 1;
    int right = x;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = static_cast<long long>(mid) * mid;

        if (square == x)
            return mid;
        else if (square < x) {
            left = mid + 1;
            result = mid;
        }
        else
            right = mid - 1;
    }

    return result;
}

int main() {
    
    assert(mySqrt(25) == 5);
    assert(mySqrt(16) == 4);

    return 0;
}