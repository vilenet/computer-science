// LeetCode: 135. Candy
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

int candy(vector<int>& ratings) {
    int n = ratings.size();
    int total = 0;
    vector<int> candies(n, 1);

    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);        
        }
    }

    for (int candy : candies) {
        total += candy;
    }

    return total;
}

int main()
{
    std::vector<int> ratings1 = {1, 0, 2};
    std::vector<int> ratings2 = {1, 2, 2};
    assert(candy(ratings1) == 5);
    assert(candy(ratings2) == 4);

    return 0;
}
