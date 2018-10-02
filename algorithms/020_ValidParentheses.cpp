#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        size_t len = s.length();
        char map['}'];
        map['('] = ')';
        map['['] = ']';
        map['{'] = '}';

        for (size_t i = 0; i < len; i++) {
            switch (s[i]) {
            case '(':
            case '{':
            case '[':
                stack.push(s[i]);
                break;
            case ')':
            case '}':
            case ']':
                if (stack.empty()) {
                    return false;
                } else if (map[stack.top()] != s[i]){
                    return false;
                } else {
                    stack.pop();
                }
            default:
                ;
            }
        }
        return stack.empty();
    }
};

int main() {
    string s("()");
    Solution sl;
    cout << sl.isValid(s) << endl;
}
