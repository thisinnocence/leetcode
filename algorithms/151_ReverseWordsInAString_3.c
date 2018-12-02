#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t parse(const char *s, char *buf, size_t bufLen) {
    size_t i = 0, j = 0, pos = bufLen - 1;
    while (s[i] == ' ' && s[i] != '\0') i++;
    j = i;
    while (s[i] != '\0') {
        while (s[j] != ' ' && s[j] != '\0') j++;
        pos -= (j - i);
        memcpy(&buf[pos], &s[i], j - i);
        if (pos > 0) {
            buf[--pos] = ' ';
        }
        while (s[j] == ' ' && s[j] != '\0') j++;
        i = j;
    }
    return buf[pos] == ' ' ? pos + 1: pos;
}

void reverseWords(char *s) {
    size_t len = strlen(s) + 1;
    char *buf = malloc(len);
    memset(buf, 0, len);
    size_t pos = parse(s, buf, len);
    strcpy(s, &buf[pos]);
    free(buf);
}

int main() {
    char s[] = "   hi he she   l";
    printf("%s\n", s);
    reverseWords(s);
    printf("%s\n", s);
}
