/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int num, int *returnSize)
{
    *returnSize = num + 1;
    int *re = (int *) malloc(sizeof(int) * (*returnSize));
    re[0] = 0;
    for (int i = 1; i <= num; i++) {
        if (i % 2 == 1) {
            re[i] = re[i-1] + 1;
        } else {
            re[i] = re[i/2]; // note: classic
        }
    }
    return re;
}
