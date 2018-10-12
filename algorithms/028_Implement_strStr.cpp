#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getNext(string &needle, int *next) {
        next[0] = -1;
        int j = 0, k = -1;
        int len = (int)needle.length();
        while (j < len - 1) {
            if (k != -1 && needle[k] != needle[j])
                k = next[k];
            else
                next[++j] = ++k;
        }
    }

    int strStr(string haystack, string needle) {
        // return (int)haystack.find(needle); // 库函数runtime 4ms, beats 98.6%
        // KMP, 经典的字符串搜索算法， 自己实现的8ms，beats 37.79% ,囧
        int subLen = (int)needle.length();
        int parLen = (int)haystack.length();
        int *next = new int[subLen];
        getNext(needle, next);
        int i = 0, j = 0;
        while (i < parLen && j < subLen) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        delete []next;
        if (j == subLen)
            return i - j;
        else
            return -1;
    }
};

int main() {
    Solution solution;
    cout << solution.strStr("hello", "ll") << endl;
    cout << solution.strStr("aaa", "bb") << endl;
    return 0;
}
