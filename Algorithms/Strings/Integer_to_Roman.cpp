// Integer to Roman
// C++17:
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

string intToRoman(int num) {
    string result;

    vector<pair<int, string>> roman = {
        {1000, "M" }, 
        {900,  "CM"}, 
        {500,  "D" }, 
        {400,  "CD"},
        {100,  "C" }, 
        {90,   "XC"}, 
        {50,   "L" }, 
        {40,   "XL"}, 
        {10,   "X" }, 
        {9,    "IX"},  
        {5,    "V" }, 
        {4,    "IV"}, 
        {1,    "I" }
    };

    for (const auto& [value, symbol] : roman) {
        while (num >= value) {
            result += symbol;
            num -=value;
        }
    }

    return result;
}

// C++11:
/*
string intToRoman(int num) {
    string result;

    vector<pair<int, string>> roman = {
        make_pair(1000, "M" ), 
        make_pair(900,  "CM"), 
        make_pair(500,  "D" ), 
        make_pair(400,  "CD"),
        make_pair(100,  "C" ),  
        make_pair(90,   "XC"),  
        make_pair(50,   "L" ),  
        make_pair(40,   "XL"),
        make_pair(10,   "X" ),   
        make_pair(9,    "IX"),   
        make_pair(5,    "V" ),
        make_pair(4,    "IV"), 
        make_pair(1,    "I" )
    };
    
    for (size_t i = 0; i < roman.size(); ++i) {
        while (num >= roman[i].first) {
            result += roman[i].second;
            num -= roman[i].first;
        }
    }
    
    return result;
}*/

// C++98:
/*
string intToRoman(int num) {
    string result;
    map<int, string, greater<int> > roman;

    roman[1000] = "M";
    roman[900]  = "CM";
    roman[500]  = "D";
    roman[400]  = "CD";
    roman[100]  = "C";
    roman[90]   = "XC";
    roman[50]   = "L";
    roman[40]   = "XL";
    roman[10]   = "X";
    roman[9]    = "IX";
    roman[5]    = "V";
    roman[4]    = "IV";
    roman[1]    = "I";
    
    for (map<int, string, greater<int> >::const_iterator it = roman.begin(); it != roman.end(); ++it) {
        while (num >= it->first) {
            result += it->second;
            num -= it->first;
        }
    }
    
    return result;
}*/

int main()
{
    int num1 = 3749;
    string exp1("MMMDCCXLIX");
    assert(intToRoman(num1) == exp1);

    int num2 = 58;
    string exp2("LVIII");
    assert(intToRoman(num2) == exp2);

    int num3 = 1994;
    string exp3("MCMXCIV");
    assert(intToRoman(num3) == exp3);

    return 0;
}

