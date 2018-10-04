#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int re = 0;
        size_t len = str.size(), i = 0;
        for (i = 0; i < len; i++) {
            if (str[i] != ' ') {
                break;
            }
        }
        if (i == len)
            return 0;

        bool isNegative = false;
        if (str[i] == '-') {
            isNegative = true;
            i++;
        } else if(str[i] == '+') {
            i++;
        }

        for (; i < len; i++) {
            if (!isdigit(str[i]))
                break;
            if (isNegative) {
                if (re < INT_MIN / 10)
                    return INT_MIN;
                if (re == INT_MIN / 10 && str[i] - '0' >= 8)
                    return INT_MIN;
                re = re * 10 - (str[i] - '0');
            } else {
                if (re > INT_MAX / 10)
                    return INT_MAX;
                if (re == INT_MAX / 10 && str[i] - '0' >= 7)
                    return INT_MAX;
                re = re * 10 + (str[i] - '0');
            }
        }
        return re;
    }
};

int main() {
    Solution sl;
    cout << sl.myAtoi("-91283472332") << endl;    // -2147483648
    cout << sl.myAtoi("words and 987") << endl;   // 0
    cout << sl.myAtoi("4193 with words") << endl; // 4193
    cout << sl.myAtoi("   -42") << endl;          // -42
    cout << sl.myAtoi("42") << endl;              // 42
    cout << sl.myAtoi("-+1") << endl;             // 0
    cout << sl.myAtoi("-6147483648") << endl;     // -2147483648
    cout << sl.myAtoi("2147483648") << endl;      //  2147483647
    return 0;
}
