int balancedStringSplit(char * s){
    int re = 0;
    int n = 0;
    while (*s) {
        *s++ == 'R' ? n++ : n--;
        if (n == 0) re++;
    }
    return re;
}
