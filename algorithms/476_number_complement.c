#include <stdio.h>

int findComplement(int num) {
    int re = 0, i = 0;
    while (num) {
        re += ((num % 2) ^ 1) << i++;
        num >>= 1;
    }
    return re;
}

int main()
{
    int n = 20161211; // 13393220
    printf("%d\n", findComplement(n));
    return 0;
}
