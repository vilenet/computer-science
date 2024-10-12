// Reverse words in a String
#include <algorithm>
#include <iostream>
#include <cassert>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string reverseWords(string s) {
    stringstream iss(s);
    stringstream oss;
    string word;
    vector<string> words;

    while (iss >> word) { 
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    for (size_t i = 0; i < words.size(); i++) {
        oss << words[i];
        if (i != words.size() - 1) {
            oss << " "; 
        }
    }

    return oss.str();
}

int main()
{
    string str1("the sky is blue");
    string exp1("blue is sky the");
    assert(reverseWords(str1) == exp1);

    string str2("  hello world  ");
    string exp2("world hello");
    assert(reverseWords(str2) == exp2);

    string str3("a good   example");
    string exp3("example good a");
    assert(reverseWords(str3) == exp3);

    return 0;
}