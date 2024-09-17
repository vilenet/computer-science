// LeetCode:
// 159. Longest Substring with At Most Two Distinct Characters
//
// Given a string s, return the length of the longest substring 
// that contains at most two distinct characters.
//
// Example:
// Input:        s = "eceba"
// Output:       3
// Explanation:  The substring is "ece" which its length is 3.
//
// Example:
// Input:        s = "ccaabbb"
// Output:       5
// Explanation:  The substring is "aabbb" which its length is 5.

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int longestSubStr(const string& s) {
	int res = 0;
	int left = 0;
	unordered_map<char, int> char_count;
	
	for (int right = 0; right < s.length(); right++) {
		char_count[s[right]]++;
		
		while (char_count.size() > 2) {
			char_count[s[left]]--;
			if (char_count[s[left]] == 0) {
				char_count.erase(s[left]);
			}
			left++;
		}

		res = max(res, right - left + 1);
	}
	
	return res;
}

int main()
{
	string s1 = "eceba";
	cout << "Max length: " << longestSubStr(s1) << endl; // 3
	
	string s2 = "ccaabbb";
	cout << "Max length: " << longestSubStr(s2) << endl; // 5
	
	return 0;
}
