// LeetCode: 
// 1876. Substrings of Size Three with Distinct Characters
// 
// Given a string s​​​​​, return the number of good substrings of length 3 in s​​​​​​.
// A string is good if there are no repeated characters.

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int countGoodSubstrings(string s) {
    int count = 0;
    if (s.size() < 3) { 
        return 0;
    }
    
    for (int i = 0; i < s.length() - 2; i++) {
        string subStr = s.substr(i, 3);
        unordered_set<char> charSet(subStr.begin(), subStr.end());
        if (charSet.size() == 3) { 
            count++; 
        }
    }

    return count;
}

int main()
{
    string str("aababcabc");
    cout << countGoodSubstrings(str) << endl;

    return 0;
}

// Explanation:
// There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
// The good substrings are "abc", "bca", "cab", and "abc".