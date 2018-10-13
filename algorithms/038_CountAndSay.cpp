#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string cur("1");
        for (int i = 1; i < n; i++) {
            string next;
            size_t len = cur.length();
            char prevChar = cur[0];
            char j = 1;
            for (size_t i = 1; i < len; i++) {
                if (cur[i] == prevChar) {
                    j++;
                } else {
                    next.push_back(j + '0');
                    next.push_back(prevChar);
                    prevChar = cur[i];
                    j = 1;
                }
            }
            next.push_back(j + '0');
            next.push_back(prevChar);
            cur = next;
        }
        return cur;
    }
};

int main() {
    Solution solution;
    cout << solution.countAndSay(6) << endl;
    return 0;
}
