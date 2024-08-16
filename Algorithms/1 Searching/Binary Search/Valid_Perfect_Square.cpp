// Valid Perfect Square
#include <iostream>
#include <cassert>

bool isPerfectSquare(int num) {
    if (num < 1) return false;

    long long left = 1;
    long long right = num;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == mid)
            return true;
        else if (square < left) 
            left = mid + 1;
        else
            right = mid - 1;
    }

    return false;
}

int main() {
    
    assert(isPerfectSquare(16) == true);
    assert(isPerfectSquare(14) == false);

    return 0;
}