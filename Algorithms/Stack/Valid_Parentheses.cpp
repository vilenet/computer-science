/*
LeetCode
20. Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true
*/
#include <iostream>
#include <cassert>
#include <string>
#include <stack>


bool isValid(std::string s) {
    std::stack<char> stack;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else {
            if (stack.empty()) return false;

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{'))
            {
                return false;
            }
        }
    }

    return stack.empty();
}

int main()
{
    std::string s1 = "()";
    std::string s2 = "()[]{}";
    std::string s3 = "(]";
    std::string s4 = "([])";

    assert(isValid(s1) == true);
    assert(isValid(s2) == true);
    assert(isValid(s3) == false);
    assert(isValid(s4) == true);

    std::cout << "All tests passed!\n";

    return 0;
}