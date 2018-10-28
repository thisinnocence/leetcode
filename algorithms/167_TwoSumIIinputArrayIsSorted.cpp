class Solution {
public:
    bool find(int target, vector<int>& numbers, int begin, int end, int &pos) {
        while (begin <= end) {
            int middle = (begin + end) / 2;
            if (target > numbers[middle] ) {
                begin = middle + 1;
            } else if (target < numbers[middle]) {
                end = middle - 1;
            } else {
                pos = middle;
                return true;
            }
        }
        return false;
    }

    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for (size_t i = 0; i < numbers.size() - 1; i++) {
            int left = target - numbers[i];
            int pos = 0;
            if (find(left, numbers, (int)i + 1, (int)numbers.size(), pos)) {
                ans.push_back(i + 1);
                ans.push_back(pos + 1);
            }
        }
        return ans;
    }
};
