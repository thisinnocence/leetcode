class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans{-1, -1};
        int left = 0, right = nums.size() - 1;
        int middle = (left + right) / 2;
        bool find = false;
        while (left <= right) {
            if (nums[middle] == target) {
                find = true;
                break;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            middle = (left + right) / 2;
        }
        if (!find) {
            return ans;
        }

        left = middle;
        right = middle;
        while (left>= 0 && nums[left] == target && left >= 0) left--;
        while (right < nums.size() && nums[right] == target && right < nums.size()) right++;
        ans[0] = left + 1;
        ans[1] = right - 1;
        return ans;
    }
};
