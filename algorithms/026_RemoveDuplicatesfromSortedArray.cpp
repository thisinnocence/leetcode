#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (ssize_t i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] == nums[i+1])
                nums.erase(nums.begin() + i);
        }
        return (int)nums.size();
    }
};

int main() {
    vector<int> ve;
    ve.push_back(1);
    ve.push_back(2);
    ve.push_back(2);
    Solution solution;
    int len = solution.removeDuplicates(ve);
    for (auto i: ve) {
        cout << i << " ";
    }
    cout << endl << len << endl;
    return 0;
}
