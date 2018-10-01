#include <stdio.h>
#include <stdlib.h>

struct AlphaNums {
    int alpha : 8;
    int num : 24;
};

int comp(const void *a, const void *b)
{
    return ((struct AlphaNums*)a)->num < ((struct AlphaNums*)b)->num;
}

char *frequencySort(char *s) {
    int charNums['z' + 1] = {0};
    int num = 0, len = 0, i, j, k;
    struct AlphaNums *alphaNums;
    char *re;

    while (*s) {
        charNums[*s]++;
        if (charNums[*s] == 1)
            num++;
        s++;
        len++;
    }

    alphaNums = (struct AlphaNums *)malloc(num * sizeof(struct AlphaNums));
    j = 0;
    for (i = 0; i < sizeof(charNums) / sizeof(int); i++) {
        if (charNums[i] > 0) {
            alphaNums[j].alpha = i;
            alphaNums[j].num = charNums[i];
            j++;
        }
    }
    qsort(alphaNums, num, sizeof(struct AlphaNums), comp);

    re = (char *)malloc(len + 1);
    k = 0;
    for (i = 0; i < num; i++) {
        for (j = 0; j < alphaNums[i].num; j++) {
            re[k++] = alphaNums[i].alpha;
        }
    }
    re[k] = '\0';

    free(alphaNums);
    return re;
}

int main()
{
    char s[] = "bcczzZZAA";
    printf("%s\n", frequencySort(s));
}
