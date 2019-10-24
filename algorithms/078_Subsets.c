/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int g_num = 0;
int g_arr[10240];
int g_size[10240];
int g_pos = 0;

void dfs(int **re, int *nums, int numsSize, int start, int subNum)
{
    if (g_pos == subNum) {
        re[g_num] = malloc(sizeof(int) * numsSize);
        memcpy(re[g_num], g_arr, sizeof(int) * numsSize);
        g_size[g_num] = subNum;
        g_num++;
        return;
    }

    for (int i = start; i < numsSize; i++) {
        g_arr[g_pos++] = nums[i];
        dfs(re, nums, numsSize, i + 1, subNum);
        g_arr[g_pos--];
    }

}

int **subsets(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
    int **re = malloc(sizeof(int *) * 10240);
    g_num = 0;

    for (int i = 0; i <= numsSize; i++) {
        g_pos = 0;
        dfs(re, nums, numsSize, 0, i);
    }
    *returnSize = g_num;
    *returnColumnSizes = malloc(sizeof(void *) * g_num);
    for (int i = 0; i < g_num; i++) {
        (*returnColumnSizes)[i] = g_size[i];
    }
    return re;
}

