#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#if 0
    // liner search
    // o(n) runtime beats 98.59%, em..
    int searchInsert(vector<int>& nums, int target) {
        if (nums[0] >= target)
            return 0;

        int i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i] >= target)
                return i;
        }
        return i;
    }
#endif

#if 0
    // recursive bi search
    // runtime beats 31.96%
    // caller: biSearch(nums, 0, nums.size(), target);
    int biSearch(vector<int>& nums, size_t begin, size_t end, int target) {
        size_t middle = (begin + end) / 2;
        if (middle == begin) {
            if (nums[begin] >= target)
                return (int)begin;
            else
                return (int)end;
        }

        if (nums[middle] > target) {
            return biSearch(nums, begin, middle, target);
        } else if (nums[middle] < target) {
            return biSearch(nums, middle + 1, end, target);
        } else {
            return (int)middle;
        }
    }
#endif

    // runtime beats 98.59%
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        while (low <= high) {
            int middle = (low + high) / 2;
            if (nums[middle] < target)
                low = middle + 1;
            else if(nums[middle] > target)
                high = middle - 1;
            else
                return middle;
        }
        // final: low = high + 1
        return low;
    }
};

int main() {
    vector<int> ve;
    ve.push_back(1);
    ve.push_back(3);
    ve.push_back(5);
    ve.push_back(6);
    ve.push_back(9);
    Solution solution;
    int re;
    re = solution.searchInsert(ve, 0);
    cout << re << endl; // 0
    re = solution.searchInsert(ve, 7);
    cout << re << endl; // 4
    re = solution.searchInsert(ve, 3);
    cout << re << endl; // 1
    re = solution.searchInsert(ve, 5);
    cout << re << endl; // 2
    return 0;
}
