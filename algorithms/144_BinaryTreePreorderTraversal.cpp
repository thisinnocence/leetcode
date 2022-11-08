/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> re;
        if (root == NULL) {
            return re;
        }
        re.push_back(root->val);
        auto left = preorderTraversal(root->left);
        re.insert(re.end(), left.begin(), left.end());
        auto right = preorderTraversal(root->right);
        re.insert(re.end(), right.begin(), right.end());
        return re;
    }
};
