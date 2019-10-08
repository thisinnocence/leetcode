void dfs(int **M, int MSize, int v, bool *visited) {
    for (int i = 0; i < MSize; i++) {
        if (M[v][i] && !visited[i]) {
            visited[i] = true;
            dfs(M, MSize, i, visited);
        }
    }
}

int findCircleNum(int** M, int MSize, int* MColSize){
    bool visited[MSize];
    memset(visited, 0, sizeof(visited));
    int num = 0;
    for (int i = 0; i < MSize; i++) {
        if (!visited[i]) {
            dfs(M, MSize, i, visited);
            num++;
        }
    }
    return num;
}

