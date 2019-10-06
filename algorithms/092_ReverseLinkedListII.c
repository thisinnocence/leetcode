/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n){
    struct ListNode *arr[n-m+1];
    struct ListNode **parr = arr;
    memset(arr, 0, sizeof(void*)*(n-m));
    struct ListNode *before_m = NULL;
    struct ListNode *after_n = NULL;
    struct ListNode *cur = head;
    int i = 0;
    if (m == n)
        return head;
    while (cur) {
        i++;
        if (m == 1) {
            before_m = NULL;
        }
        if (i == m - 1 && m > 1) {
            before_m = cur;
        }
        if (i >= m && i <= n) {
            *parr++ = cur;
        }    
        if (i == n + 1) {
            after_n = cur;
        }
        cur = cur->next;
    }
    for (i = n-m; i >= 1; i--) {
        arr[i]->next = arr[i-1];
    }
    if (before_m) {
        before_m->next = arr[n-m];
    }
    arr[0]->next = after_n;
    if (!before_m) {
        return arr[n-m];
    } else {
        return head;
    }
}

