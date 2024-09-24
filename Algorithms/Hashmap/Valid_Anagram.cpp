/*
LeetCode 
242. Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false

Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
*/
#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, int> charCount;
    for (char c : s) charCount[c]++;
    for (char c : t) {
        if (charCount[c] == 0) return false;
        charCount[c]--;
    }
    
    return true;
}

int main()
{
    assert(isAnagram("anagram", "nagaram") == true);
    assert(isAnagram("rat", "car") == false);

    return 0;
}