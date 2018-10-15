/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        size_t size = nums.size();
        if (size == 0) return NULL;
        if (size == 1) return new TreeNode(nums[0]);
        size_t middle = size / 2;
        TreeNode *tree = new TreeNode(nums[middle]);
        vector<int> leftNums(nums.begin(), nums.begin() + middle);
        vector<int> rightNums(nums.begin() + middle + 1, nums.end());
        tree->left = sortedArrayToBST(leftNums);
        tree->right = sortedArrayToBST(rightNums);
        return tree;
    }
};
