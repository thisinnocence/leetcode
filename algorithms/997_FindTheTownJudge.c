int findJudge(int N, int** trust, int trustSize, int* trustColSize){
    int trustNum[1001] = {0};
    int judge = -1;
    for (int i = 0; i < trustSize; i++) {
        trustNum[trust[i][1]]++;
    }
    for (int i = 1; i <= N; i++) {
        if (trustNum[i] == N - 1) {
            judge = i;
            break;
        }
    }
    for (int i = 0; i < trustSize; i++) {
        if (trust[i][0] == judge) {
            return -1;
        }
    }
    return judge;
}

