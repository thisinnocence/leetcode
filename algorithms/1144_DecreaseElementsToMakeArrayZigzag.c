int moveNums(int *nums, int numsSize, int flag)
{
    int re = 0;
    int arr[numsSize];
    memcpy(arr, nums, sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; i++) {
        if (i % 2 == flag) {
            if (i + 1 < numsSize && arr[i] <= arr[i + 1]) {
                re += arr[i + 1] - arr[i] + 1;
                arr[i + 1] = arr[i] - 1;
            }
            if (i - 1 >= 0 && arr[i] <= arr[i - 1]) {
                re += arr[i - 1] - arr[i] + 1;
                arr[i - 1] = arr[i] - 1;
            }
        }
    }
    return re;
}

int movesToMakeZigzag(int *nums, int numsSize)
{
    int re1 = moveNums(nums, numsSize, 0);
    int re2 = moveNums(nums, numsSize, 1);
    return re1 < re2 ? re1 : re2;
}
