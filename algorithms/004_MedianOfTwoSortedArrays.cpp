// DP algorithm. runtime 36ms
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int left = (m + n + 1) / 2;
        int right = (m + n + 2) / 2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }
    int findKth(vector<int>& nums1, int i, vector<int>& nums2, int j, int k) {
        if (i >= nums1.size())
            return nums2[j + k - 1];
        if (j >= nums2.size())
            return nums1[i + k - 1];
        if (k == 1)
            return min(nums1[i], nums2[j]);

        int midVal1 = (i + k / 2 - 1 < nums1.size()) ? nums1[i + k / 2 - 1] : INT_MAX;
        int midVal2 = (j + k / 2 - 1 < nums2.size()) ? nums2[j + k / 2 - 1] : INT_MAX;
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k / 2, nums2, j, k - k / 2);
        } else {
            return findKth(nums1, i, nums2, j + k / 2, k - k / 2);
        }
    }
};

#if 0
class Solution {
public:
    // o(m + n), runtime 36ms
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> all;
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 <= *it2) {
                all.push_back(*it1);
                it1++;
            } else {
                all.push_back(*it2);
                it2++;
            }
        }
        while (it1 != nums1.end()) {
            all.push_back(*it1);
            it1++;
        }
        while (it2 != nums2.end()) {
            all.push_back(*it2);
            it2++;
        }

        size_t len = all.size();
        if (len % 2 == 0) {
            return ((double)all[len / 2] + all[len / 2 - 1]) / 2;
        } else {
            return all[len / 2];
        }
    }
};
#endif
