/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <string.h>
int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    int *re = (int *)malloc(2*sizeof(int));
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                re[0] = i;
                re[1] = j;
                return re;
            }
        }
    }
    return re;
}
