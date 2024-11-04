// 17. Letter Combinations of a Phone Number
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

void backtrack(
    const string& digits, 
    const unordered_map<char, string>& buttonMap, 
    int index,
    string current, 
    vector<string>& result) 
{
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }

    char digit = digits[index];
    const string& letters = buttonMap.at(digit);

    for (char letter : letters) {
        backtrack(digits, buttonMap, index + 1, current + letter, result);
    }
}

vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};

    unordered_map<char, string> buttonMap {
        {'1', ""},     {'2', "abc"}, {'3', "def"},
        {'4', "ghi"},  {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> result;
    backtrack(digits, buttonMap, 0, "", result);
    return result;
}

int main()
{
    string digits1 = "23";
    vector<string> Output1 = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
    assert(letterCombinations(digits1) == Output1);

    string digits2 = "";
    vector<string> Output2 = {};
    assert(letterCombinations(digits2) == Output2);

    string digits3 = "2";
    vector<string> Output3 = {"a","b","c"};
    assert(letterCombinations(digits3) == Output3);

    return 0;
}