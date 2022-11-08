struct ListNode *swapPairs(struct ListNode *head)
{
    if (!head || !head->next)
        return head;

    // >= 2 nodes
    struct ListNode *first = head;
    struct ListNode *second = head->next;
    struct ListNode *newHead = head->next;
    struct ListNode *pre = NULL;

    while (first && second) {
        // swap first, second
        struct ListNode *secondNext = second->next;
        second->next = first;
        first->next = secondNext;

        // cat pre
        if (pre) {
            pre->next = second;
        }

        // forward
        pre = first;
        first = secondNext;
        if (secondNext) {
            second = secondNext->next;
        } else {
            second = NULL;
        }
    }

    return newHead;
}
