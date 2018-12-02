#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WordList {
    char *word;
    struct WordList *next;
};

void insert(struct WordList **head, char *word) {
    struct WordList *node = malloc(sizeof(struct WordList));
    node->next = *head;
    node->word = word;
    *head = node;
}

void parse(const char *s, struct WordList **head) {
    size_t i = 0, j = 0;
    while (s[i] == ' ' && s[i] != '\0') i++;
    j = i;
    while (s[i] != '\0') {
        while (s[j] != ' ' && s[j] != '\0') j++;
        char *word = malloc(j - i + 1);
        memcpy(word, &s[i], j - i);
        word[j - i] = '\0';
        insert(head, word);
        while (s[j] == ' ' && s[j] != '\0') j++;
        i = j;
    }
}

void reverseWords(char *s) {
    struct WordList *head = NULL;
    parse(s, &head);
    struct WordList *cur = head, *tmp;
    s[0] = 0;
    while (cur) {
        strcat(s, cur->word);
        if (cur->next) {
            strcat(s, " ");
        }
        tmp = cur;
        cur = cur->next;
        free(tmp->word);
        free(tmp);
    }
}

int main() {
    char s[] = "this is a super man";
    printf("%s\n", s);
    reverseWords(s);
    printf("%s", s);
}
