int comp(const void *a, const void *b)
{
    int va = (*(struct ListNode **) a)->val;
    int vb = (*(struct ListNode **) b)->val;
    return va > vb;
}

struct ListNode *sortList(struct ListNode *head)
{
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *curr = head;
    struct ListNode *arr[1024*1024];
    int num = 0;
    while (curr) {
        arr[num++] = curr;
        curr = curr->next;
    }
    qsort(arr, num, sizeof(void *), comp);
    int i = 0;
    for (; i < num - 1; i++) {
        arr[i]->next = arr[i + 1];
    }
    arr[i]->next = NULL;
    return arr[0];
}
