#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // 动态规划
    int maxSubArray(vector<int>& nums) {
        int re = nums[0], sum = 0;
        for (size_t i = 0; i < nums.size(); i++) {
            sum += nums[i];
            re = max(sum, re);
            sum = max(sum, 0);
        }
        return re;
    }
};

int main() {
    Solution solution;
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums(a, a + sizeof(a)/sizeof(a[0]));
    cout << solution.maxSubArray(nums) << endl; // [4,-1,2,1]  largest sum = 6.
    return 0;
}
