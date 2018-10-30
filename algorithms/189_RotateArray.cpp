#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (k == 0) return;
        k %= nums.size();
        vector<int> ans(nums.end() - k, nums.end());
        ans.insert(ans.end(), nums.begin(), nums.begin() + nums.size() - k);
        nums = ans;
    };
};

int main() {
    Solution s;
    // int a[] = {1, 2, 3, 4, 5, 6, 7};
    int a[] = {1, 2};
    vector<int> tmp(a, a + sizeof(a) / sizeof(a[0]));
    s.rotate(tmp, 1);  // [5,6,7,1,2,3,4]
    for (auto i : tmp) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
