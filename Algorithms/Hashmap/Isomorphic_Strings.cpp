/*
LeetCode
205. Isomorphic Strings

Given two strings s and t, determine if they are isomorphic.

Two strings s and t are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while 
preserving the order of characters. No two characters may map to the same character, 
but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true
Explanation:
The strings s and t can be made identical by:
Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:
Input: s = "foo", t = "bar"
Output: false
Explanation:
The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:
Input: s = "paper", t = "title"
Output: true

Constraints:

1 <= s.length <= 5 * 104
t.length == s.length
s and t consist of any valid ascii character.
*/
#include <iostream>
#include <string>
#include <cassert>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;

    unordered_map<char, char> s2t, t2s;

    for (int i = 0; i < s.size(); ++i) {
        char char_s = s[i];
        char char_t = t[i];

        if (s2t.count(char_s) && s2t[char_s] != char_t) return false;
        else s2t[char_s] = char_t;
    
        if (t2s.count(char_t) && t2s[char_t] != char_s) return false;
        else t2s[char_t] = char_s;
    }

    return true;
}

int main()
{
    assert(isIsomorphic("egg", "add") == true);
    assert(isIsomorphic("foo", "bar") == false );
    assert(isIsomorphic("paper", "title") == true);

    return 0;
}