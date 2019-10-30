char g_str[1024];
char g_pos;
char **g_re;
int g_num;

bool vaild(char *str) {
    int top = 0;
    while (*str) {
        *str++ == '(' ? top++ : top--;
        if (top < 0) return false;
    }
    return top == 0;
}

void dfs(int n) {
    if (n == 0) {
        g_str[g_pos] = '\0';
        if (vaild(g_str)) g_re[g_num++] = strdup(g_str);
        return;
    }

    char *brackets = "()";
    for (int i = 0; i < 2; i++) {
        if (g_pos == 0 && brackets[i] == ')') continue;
        g_str[g_pos++] = brackets[i];
        dfs(n - 1);
        g_pos--;
    }
}

char **generateParenthesis(int n, int *returnSize) {
    g_re = malloc(102400 * sizeof(char *)); // note: must malloc enought :)
    g_num = 0;
    g_pos = 0;
    dfs(n * 2);
    *returnSize = g_num;
    return g_re;
}
