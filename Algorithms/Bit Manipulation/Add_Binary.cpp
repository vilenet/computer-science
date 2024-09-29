/*
LeetCode
67. Add Binary

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 
Constraints:

1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
#include <iostream>
#include <cassert>
#include <string>
#include <bitset>
using namespace std;

std::string addBinary(std::string a, std::string b) {
    std::string result = "";  
    int i = a.length() - 1; 
    int j = b.length() - 1; 
    int carry = 0; 

    while (i >= 0 || j >= 0 || carry) {
        int bitA = (i >= 0) ? a[i--] - '0' : 0;
        int bitB = (j >= 0) ? b[j--] - '0' : 0;

        int sum = bitA ^ bitB ^ carry;   
        carry = (bitA & bitB) | (carry & (bitA ^ bitB));

        result += (sum ? '1' : '0');
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// This solution can work up to 64:
// string addBinary(string a, string b) {
    
//     long long num_a = std::stoll(a, nullptr, 2);
//     long long num_b = std::stoll(b, nullptr, 2);

//     while (num_b != 0) {
//         long long sum = num_a ^ num_b;
//         long long carry = (num_a & num_b) << 1;
//         num_b = carry;
//         num_a = sum;
//     }
    
//     string res = bitset<64>(num_a).to_string();
//     size_t pos = res.find('1');

//     if (pos != string::npos) {
//         return res.substr(pos);
//     }

//     return "0";
// }

void test_addBinary() {
    string res = addBinary("1010", "1011");
    string expected = "10101";

    assert(res == expected);
    cout << "Ok\n";
}

int main()
{
    test_addBinary();
    return 0;
}