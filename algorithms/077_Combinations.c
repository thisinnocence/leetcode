/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int g_retNum = 0;
int g_arr[10240];
int g_pos = 0;

void dfs(int **re, int n, int k, int start)
{
    if (g_pos == k) {
        re[g_retNum] = malloc(sizeof(int) * k);
        memcpy(re[g_retNum], g_arr, sizeof(int) * k);
        g_retNum++;
        return;
    }
    for (int i = start; i <= n; i++) {
        g_arr[g_pos++] = i;
        dfs(re, n, k, i + 1);
        g_pos--;
    }
}

int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
    g_retNum = 0;
    g_pos = 0;
    int **re = malloc(sizeof(int *) * 10240);
    dfs(re, n, k, 1);
    *returnSize = g_retNum;
    *returnColumnSizes = malloc(sizeof(void *) * g_retNum);
    for (int i = 0; i < g_retNum; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return re;
}

