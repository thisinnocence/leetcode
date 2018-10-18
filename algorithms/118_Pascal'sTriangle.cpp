class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        if (numRows == 0) return ans;

        vector<int> row;
        row.push_back(1);
        ans.push_back(row);
        if (numRows == 1) return ans;

        row.push_back(1);
        ans.push_back(row);
        if (numRows == 2) return ans;

        for (size_t i = 2; i < numRows; i++) {
            vector<int> cur;
            cur.push_back(1);
            for (size_t j = 1; j < ans.size(); j++) {
                cur.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            cur.push_back(1);
            ans.push_back(cur);
        }
        return ans;
    }
};
