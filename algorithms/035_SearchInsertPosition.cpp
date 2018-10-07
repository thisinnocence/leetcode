#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//    o(n) runtime beats 98.59%, em..
//    int searchInsert(vector<int>& nums, int target) {
//        if (nums[0] >= target)
//            return 0;
//
//        int i = 1;
//        for (; i < nums.size(); i++) {
//            if (nums[i] >= target)
//                return i;
//        }
//        return i;
//    }

    // runtime beats 31.96% .., I think because recursive
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

    int searchInsert(vector<int>& nums, int target) {
        return biSearch(nums, 0, nums.size(), target);
    }
};

int main() {
    vector<int> ve;
    ve.push_back(1);
    ve.push_back(3);
    ve.push_back(5);
    ve.push_back(6);
    Solution solution;
    int re;
    re = solution.searchInsert(ve, 0);
    cout << re << endl; // 0
    re = solution.searchInsert(ve, 7);
    cout << re << endl; // 4
    re = solution.searchInsert(ve, 3);
    cout << re << endl; // 1
    return 0;
}
