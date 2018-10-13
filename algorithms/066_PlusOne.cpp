class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int last = digits[digits.size()-1] + 1;
        int carry = last / 10, left = last % 10;
        ans.push_back(left);
        for (int i = (int)digits.size() - 2; i >= 0; i--) {
            int tmp = digits[i] + carry;
            carry = tmp / 10;
            left = tmp % 10;
            ans.push_back(left);
        }
        if (carry > 0)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
