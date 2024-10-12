// Roman to Integer
#include <iostream>
#include <cassert>
#include <string>
#include <vector>
using namespace std;

int value(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(string s) {
    int sum = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (i > 0 && value(s[i]) > value(s[i - 1])) {
            sum += value(s[i]) - (2 * value(s[i - 1]));
        }
        else {
            sum += value(s[i]);
        }
    }

    return sum;
}

int main()
{
    string rom1("III");
    int exp1 = 3;
    assert(romanToInt(rom1) == exp1);

    string rom2("LVIII");
    int exp2 = 58;
    assert(romanToInt(rom2) == exp2);

    string rom3("MCMXCIV");
    int exp3 = 1994;
    assert(romanToInt(rom3) == exp3);

    return 0;
}

