/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX_SIZE 10240
#define STR_SIZE 15

struct StrRecord {
    char str[STR_SIZE];
    int pos;
};

struct StrRecord g_str;
int g_num = 0;
char **g_re;

void backTrace(char *S, int len, int start)
{
    if (g_str.pos == len) {
        g_re[g_num++] = strdup(g_str.str);
    }

    for (int i = start; i < len; i++) {
        if (isalpha(S[i])) {
            int tmpLower = tolower(S[i]);
            g_str.str[g_str.pos++] = tmpLower;
            backTrace(S, len, i + 1);
            g_str.str[g_str.pos--];
            int tmpUpper = toupper(S[i]);
            g_str.str[g_str.pos++] = tmpUpper;
        } else {
            g_str.str[g_str.pos++] = S[i];
        }
        backTrace(S, len, i + 1);
        g_str.str[g_str.pos--];
    }
}

char **letterCasePermutation(char *S, int *returnSize)
{
    g_re = malloc(sizeof(char *) * MAX_SIZE);
    g_num = 0;
    memset(&g_str, 0, sizeof(g_str));
    int len = strlen(S);
    backTrace(S, len, 0);
    *returnSize = g_num;
    return g_re;
}

