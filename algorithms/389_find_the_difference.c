char findTheDifference(char* s, char* t) {
    char re = 0;
    while (*t) {
        re += *t - *s;
        t++;
        s++;
    }
    return re;
}
