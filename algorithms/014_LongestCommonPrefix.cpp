#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";

        string re;
        size_t i = 0;
        while (1) {
            char c = strs[0][i];
            for (auto str: strs) {
                if (i >= str.size() || str[i] != c)
                    goto done;
            }
            i++;
        }
    done:
        return strs[0].substr(0,i);
    }
};

int main() {
    Solution solution;
    vector<string> ve;
    ve.push_back("flower");
    ve.push_back("flow");
    ve.push_back("flight");
    cout << solution.longestCommonPrefix(ve) << endl;
    return 0;
}
