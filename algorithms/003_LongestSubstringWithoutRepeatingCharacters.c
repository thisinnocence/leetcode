#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
    char *table[128] = {NULL};
    int len = 0, re = 0;
    char *cur = s;

    while (*cur) {
        if (table[*cur] != NULL) {
            // meet same char, cur should move back: len - 1
            re = re < len ? len : re;
            memset(table, 0, sizeof(table));
            cur -= len - 1;
            len = 0;
        }
        table[*cur] = cur;
        len++;
        cur++;
    }
    re = re < len ? len : re;

    return re;
}

int main()
{
    int num = lengthOfLongestSubstring("dvdf");
    printf("%d\n", num);
    return 0;
}
