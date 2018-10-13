#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt = 0;
        for (int i = (int)s.length() - 1; i >= 0; i--) {
            if (isalpha(s[i])) {
                cnt++;
            } else {
                if (cnt == 0)
                    continue;
                else
                    break;
            }
        }
        return cnt;
    }
};

int main() {
    Solution solution;
    cout << solution.lengthOfLastWord("hello world   ") << endl;
    return 0;
}
