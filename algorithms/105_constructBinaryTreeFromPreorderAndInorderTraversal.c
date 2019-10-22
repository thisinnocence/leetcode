/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode *buildTree(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    if (preorderSize == 0)
        return NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));
    root->val = preorder[0];
    root->left = NULL;
    root->right = NULL;
    if (preorderSize <= 1)
        return root;

    int leftNum = 0;
    for (; leftNum < inorderSize; leftNum++) {
        if (inorder[leftNum] == preorder[0])
            break;
    }

    if (leftNum > 0)
        root->left = buildTree(&preorder[1], leftNum, &inorder[0], leftNum);

    int rightNum = preorderSize - leftNum - 1;
    if (rightNum > 0)
        root->right = buildTree(&preorder[leftNum + 1], rightNum, &inorder[leftNum + 1], rightNum);

    return root;
}

