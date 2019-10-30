/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


struct TreeNode *mergeTrees(struct TreeNode *t1, struct TreeNode *t2)
{
    if (!t1 && !t2) return NULL;
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = 0;
    node->left = NULL;
    node->right = NULL;

    struct TreeNode *left1 = NULL, *left2 = NULL, *right1 = NULL, *right2 = NULL;

    if (t1) {
        node->val += t1->val;
        left1 = t1->left;
        right1 = t1->right;
    }

    if (t2) {
        node->val += t2->val;
        left2 = t2->left;
        right2 = t2->right;
    }

    if (left1 ||left2) node->left = mergeTrees(left1, left2);
    if (right1 || right2) node->right = mergeTrees(right1, right2);

    return node;
}
