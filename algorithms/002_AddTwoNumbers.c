#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* p = head;
    struct ListNode* last = NULL;

    while (l1 || l2) {
        if (l1 && l2) {
            sum = (l1->val + l2->val + carry);
            p->val = sum % 10;
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        } else if(l1 && !l2) {
            sum = l1->val + carry;
            p->val = sum % 10;
            carry = sum / 10;
            l1 = l1->next;
        } else if(!l1 && l2) {
            sum = l2->val + carry;
            p->val = sum % 10;
            carry = sum / 10;
            l2 = l2->next;
        }
        p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        last = p;
        p = p->next;
        p->val = 0;
        p->next = NULL;
    }

    if (carry) {
        p->val = carry;
    } else {
        last->next = NULL;
        free(p);
    }
    return head;
}

int main() {
    // 2 4 3
    // 5 6 4
    struct ListNode arr1[3];
    struct ListNode arr2[3];
    struct ListNode *re;

    arr1[0].val = 2;
    arr1[0].next = arr1 + 1;
    arr1[1].val = 4;
    arr1[1].next = arr1 + 2;
    arr1[2].val = 3;
    arr1[2].next = NULL;

    arr2[0].val = 5;
    arr2[0].next = arr2 + 1;
    arr2[1].val = 6;
    arr2[1].next = arr2 + 2;
    arr2[2].val = 4;
    arr2[2].next = NULL;

    re = addTwoNumbers(arr1, arr2);
    while (re) {
        printf("%d ", re->val);
        re = re->next;
    }
    printf("\n");
    return 0;

}
