class Solution {
private:
    vector<int> path;
    vector<int> candidates;
    vector<vector<int>> res;

public:
    void dfs(int target, int start)
    {
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (size_t i = start; i < candidates.size() && target - candidates[i] >= 0; i++) {
            path.push_back(candidates[i]);
            dfs(target - candidates[i], i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        this->candidates = candidates;
        sort(this->candidates.begin(), this->candidates.end());
        dfs(target, 0);
        return res;
    }
};

