class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) return 0;
        for (ssize_t i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] == val)
                nums.erase(nums.begin() + i);
        }
        return (int)nums.size();
    }
};
