/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void trave(struct TreeNode *root, int *re, int *num) {
    if (root == NULL)
        return;
    
    trave(root->left, re, num);
    re[(*num)++] = root->val;
    trave(root->right, re, num);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int *re = malloc(1024*sizeof(int));
    *returnSize = 0;
    trave(root, re, returnSize);
    return re;
}

