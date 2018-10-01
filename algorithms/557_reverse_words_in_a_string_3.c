#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseWords(char* s) {
    int i = 0, j = 0, k = 0;
    int len, tmp;
    char *re;

    len = 1024 * 64;
    re = (char *)malloc(len);
    for (;;) {
        if (s[i] == ' ' || s[i] == '\0') {
            tmp = i;
            while (tmp > j)
                re[k++] = s[--tmp];

            if (s[i] == ' ')
                re[k++] = ' ';
            else
                break;

            i++;
            while(s[i] == ' ') {
                i++;
                re[k++] = ' ';
            }
            j = i;
        }
        i++;
    }
    re[k] = '\0';
    return re;
}

int main()
{
    char *s = "Let's take LeetCode contest";
    printf("%s\n", reverseWords(s));
    return 0;
}
