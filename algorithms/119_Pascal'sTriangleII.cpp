class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if (rowIndex == 0) return ans;

        ans.push_back(1);
        if (rowIndex == 1) return ans;

        for (int i = 2; i <= rowIndex; i++) {
            vector<int> cur;
            cur.push_back(1);
            for (size_t j = 0; j < ans.size() - 1; j++) {
                cur.push_back(ans[j] + ans[j+1]);
            }
            cur.push_back(1);
            ans = cur;
        }
        return ans;
    }
};
