#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        short value['Z'];
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        int re = 0;
        size_t len = s.length();
        for (size_t i = 1; i < len; i++) {
            if (value[s[i-1]] < value[s[i]])
                re -= value[s[i-1]];
            else
                re += value[s[i-1]];
        }
        return re + value[s[len-1]];
    }
};

int main() {
    Solution solution;
    cout << solution.romanToInt("IV") << endl;      // 4
    cout << solution.romanToInt("MCMXCIV") << endl; // 1994
    cout << solution.romanToInt("LVIII") << endl;   // 58
    return 0;
}
