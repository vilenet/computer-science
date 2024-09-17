// LeetCode 
// 1732. Find the Highest Altitude
#include <iostream>
#include <vector>
using namespace std;

int largestAltitude(vector<int>& gain) {
    int maxPoint = 0, currentSum = 0;

    for (const int& n : gain) {
        currentSum += n;
        if (currentSum > maxPoint) {
            maxPoint = currentSum;
        }
    }

    return maxPoint;
}

int main()
{
    vector<int> gain1 = {-5,1,5,0,-7};       // 1
    cout << largestAltitude(gain1) << endl;

    vector<int> gain2 = {-4,-3,-2,-1,4,3,2}; // 0
    cout << largestAltitude(gain2) << endl;

    return 0;
}
