int g_lineSize;
int g_colSize;
char **g_board;
bool **g_visited;

bool static inline valid(int i, int j)
{
    return i >= 0 && j >= 0 && i < g_lineSize && j < g_colSize;
}

bool dfs(int i, int j, char *start)
{
    if (start[1] == '\0')
        return g_board[i][j] == *start;

    if (g_board[i][j] != *start)
        return false;

    static const char dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    g_visited[i][j] = true;
    for (int k = 0; k < 4; k++) {
        int new_i = i + dir[k][0];
        int new_j = j + dir[k][1];
        if (valid(new_i, new_j) && !g_visited[new_i][new_j]) {
            if (dfs(new_i, new_j, start + 1))
                return true;
        }
    }
    g_visited[i][j] = false;

    return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    g_colSize = *boardColSize;
    g_lineSize = boardSize;
    g_board = board;

    bool *visited[boardSize];
    for(int i = 0; i < boardSize; i++) {
        visited[i] = malloc(sizeof(bool)*g_colSize);
        memset(visited[i], 0, sizeof(bool)*g_colSize);
    }
    g_visited = visited;

    bool re = false;
    for (int i = 0; i < g_lineSize; i++) {
        for (int j = 0; j < g_colSize; j++) {
            if (board[i][j] == *word) {
                if (dfs(i, j, word)) {
                    re = true;
                    goto done;
                }
            }
        }
    }

done:
    for(int i = 0; i < boardSize; i++) {
        free(visited[i]);
    }
    return re;
}

