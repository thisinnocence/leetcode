class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n != 0) {
            int remain = n % 26;
            if (remain == 0) {
                remain = 26;
            }
            ans.push_back(remain + 'A' - 1);
            n /= 26;
            if (remain == 26) {
                n -= 1;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
