class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = (int)a.length() - 1, j = (int)b.length() - 1;
        char sum = a[i] + b[j] - 2 * '0';
        char carry = sum / 2;
        char left = sum % 2;
        ans.push_back(left + '0');
        i--, j--;
        while (i >= 0 || j >= 0) {
            sum = 0;
            if (i >= 0) {
                sum += a[i--] - '0';
            }
            if (j >= 0) {
                sum += b[j--] - '0';
            }
            sum += carry;
            carry = sum / 2;
            left = sum % 2;
            ans.push_back(left + '0');
        }
        if (carry > 0)
            ans.push_back(carry + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
