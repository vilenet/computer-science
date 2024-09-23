/*
LeetCode
383. Ransom Note

Given two strings ransomNote and magazine, return true if ransomNote can be
 constructed by using the letters from magazine and false otherwise.

Each letter in magazine can only be used once in ransomNote.

 
Example 1:
Input: ransomNote = "a", magazine = "b"
Output: false

Example 2:
Input: ransomNote = "aa", magazine = "ab"
Output: false

Example 3:
Input: ransomNote = "aa", magazine = "aab"
Output: true
*/
#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> charCount;

    for (char c : magazine) { 
        charCount[c]++;
    }

    for (char c : ransomNote) {
        if (charCount[c] == 0) return false;
        charCount[c]--;
    }

    return true;
}

int main()
{
    assert(canConstruct("a", "b") == false);
    assert(canConstruct("aa", "ab") == false);
    assert(canConstruct("aa", "aab") == true);
    assert(canConstruct("aa", "aa") == true);

    return 0;
}