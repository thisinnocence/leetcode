/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define MAX_NUM 10240

struct combine {
    int num[MAX_NUM];
    int pos;
};

struct combine g_comb;
int **g_re;
int g_re_num;
int *g_column;

void dfs(int *candidates, int candidatesSize, int target, int start)
{
    if (target == 0) {
        g_re[g_re_num] = malloc(sizeof(int) * g_comb.pos);
        memcpy(g_re[g_re_num], g_comb.num, sizeof(int) * g_comb.pos);
        g_column[g_re_num] = g_comb.pos;
        g_re_num++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (target < 0) continue;
        if (i > start && candidates[i] == candidates[i - 1]) continue;
        g_comb.num[g_comb.pos++] = candidates[i];
        dfs(candidates, candidatesSize, target - candidates[i], i + 1);
        g_comb.pos--;
    }

}

int comp(const void *p1, const void *p2)
{
    return *(int *) p1 > *(int *) p2;
}

int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
    g_re = malloc(sizeof(int *) * MAX_NUM);
    g_re_num = 0;
    g_column = malloc(sizeof(int) * MAX_NUM);
    memset(&g_comb, 0, sizeof(g_comb));

    qsort(candidates, candidatesSize, sizeof(int), comp);
    dfs(candidates, candidatesSize, target, 0);
    *returnSize = g_re_num;
    *returnColumnSizes = g_column;
    return g_re;
}
