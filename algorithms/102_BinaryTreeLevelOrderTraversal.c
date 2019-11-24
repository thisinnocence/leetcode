/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX_QUE 10240
struct queue {
    int head;
    int tail;
    int num;
    struct TreeNode *array[MAX_QUE];
};

bool empty(struct queue *q)
{
    return q->num == 0;
}

void push(struct queue *q, struct TreeNode *node)
{
    if (q->num == MAX_QUE) {
        printf("push fail, queue full");
        return;
    }

    if (!empty(q)) {
        q->tail = (q->tail + 1) % MAX_QUE;
    }
    q->array[q->tail] = node;
    q->num++;
}

void pop(struct queue *q)
{
    if (empty(q)) {
        printf("pop fail, queue empty");
        return;
    }

    q->head = (q->head + 1) % MAX_QUE;
    q->num--;
}


struct TreeNode *front(struct queue *q)
{
    if (q->num == 0)
        return NULL;

    return q->array[q->head];
}

void initQueue(struct queue *q)
{
    memset(q, 0, sizeof(*q));
}

int **levelOrder(struct TreeNode *root, int *returnSize, int **returnColumnSizes)
{
    *returnSize = 0;
    *returnColumnSizes = 0;
    if (root == NULL)
        return NULL;

    struct queue *q = malloc(sizeof(struct queue));
    initQueue(q);
    int **re = malloc(10240 * sizeof(int *));
    *returnColumnSizes = malloc(10240 * sizeof(int));
    int layer = 0;
    push(q, root);
    while (!empty(q)) {
        int curNum = q->num;
        int *array = malloc(sizeof(int) * curNum);
        (*returnColumnSizes)[layer] = curNum;
        for (int i = 0; i < curNum; i++) {
            struct TreeNode *node = front(q);
            if (node) {
                array[i] = node->val;
                if (node->left) push(q, node->left);
                if (node->right) push(q, node->right);
            }
            pop(q);
        }
        re[layer++] = array;
    }
    *returnSize = layer;
    free(q);
    return re;
}
