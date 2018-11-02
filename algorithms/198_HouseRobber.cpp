class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp = {nums[0], max(nums[0], nums[1])};
        for (int i = 2; i < nums.size(); i++) {
            int curMax = max(nums[i] + dp[i - 2], dp[i - 1]);
            dp.push_back(curMax);
        }
        return dp.back();
    }
};
