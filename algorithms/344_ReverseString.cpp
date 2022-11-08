void reverseString(char* s, int sSize){
    if (sSize == 0) {
        return;
    }
    char tmp[sSize];
    for (int i = 0; i < sSize; i++) {
        tmp[i] = s[i];
    }
    for (int i = sSize - 1; i >= 0; i--) {
        *s++ = tmp[i];
    }
}
