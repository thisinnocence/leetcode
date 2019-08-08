/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) {
       return NULL;
    }
    struct TreeNode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    if (root->left != NULL) {
        invertTree(root->left);
    }
    if (root->right != NULL) {
        invertTree(root->right);
    }
    return root;
}

