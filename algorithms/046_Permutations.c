/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int g_num = 0;
int g_arr[10240];
int g_pos = 0;
bool g_visited[10240];

void dfs(int **re, int *nums, int numsSize, int start)
{
    if (g_pos == numsSize) {
        re[g_num] = malloc(sizeof(int) * numsSize);
        memcpy(re[g_num], g_arr, sizeof(int) * numsSize);
        g_num++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        if (g_visited[i])
            continue;
        g_arr[g_pos++] = nums[i];
        g_visited[i] = true;
        dfs(re, nums, numsSize, 0);
        g_arr[g_pos--];
        g_visited[i] = false;
    }

}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    g_num = 0;
    g_pos = 0;
    memset(g_visited, false, sizeof(g_visited));
    int **re = malloc(sizeof(int *) * 10240);
    dfs(re, nums, numsSize, 0);
    *returnSize = g_num;
    *returnColumnSizes = malloc(sizeof(void *) * g_num);
    for (int i = 0; i < g_num; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
    return re;
}
