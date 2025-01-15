// Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
#include <iostream>
#include <vector>
using namespace std;


void backtrack(int start, int n, int k, vector<int>& combination, vector<vector<int>>& result) {
    if (combination.size() == k) {                   // If the combination is complete, add it to the result
        result.push_back(combination);
        return;
    }
         
    for (int i = start; i <= n; ++i) {               // Iterate through numbers from the current `start` to `n`
        combination.push_back(i);                    // Add the number to the current combination
        backtrack(i + 1, n, k, combination, result); // Recursively continue to build the combination
        combination.pop_back();                      // Backtrack to the previous state (remove the last number)
    }
}

vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> result;
    vector<int> combination;
    result.reserve(1 << n);                          // Reserve space to avoid multiple allocations
    backtrack(1, n, k, combination, result);         // Start backtracking with the initial index 1
    return result;
}


int main() 
{
    int n = 4, k = 2;

    vector<vector<int>> combinations = combine(n, k);

    for (const auto& comb : combinations) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
