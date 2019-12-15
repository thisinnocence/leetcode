int path[16];
int curr;
int max_val;

int get_ans(char **arr)
{
    char table['z' + 1] = {0};
    int ans = 0;
    for (int i = 0; i < curr; i++) {
        char *p = arr[path[i]];
        while (*p) {
            if (table[*p]) return 0;
            table[*p] = 1;
            p++;
            ans++;
        }
    }
    return ans;
}

void dfs(char **arr, int num, int dest, int start)
{
    if (curr == dest) {
        int ans = get_ans(arr);
        if (max_val < ans) max_val = ans;
        return;
    }

    for (int i = start; i < num; i++) {
        path[curr++] = i;
        dfs(arr, num, dest, i + 1);
        curr--;
    }
}

int maxLength(char **arr, int arrSize)
{
    curr = 0;
    max_val = 0;
    for (int i = 1; i <= arrSize; i++) {
        dfs(arr, arrSize, i, 0);
    }
    return max_val;
}
