class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto i = 0; i < nums.size(); i++) {
          if (s.count(nums[i]) == 1)
              return true;
          s.insert(nums[i]);
        }
        return false;
    }
};
