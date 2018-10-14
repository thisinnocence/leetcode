/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL)
            return head;
        if (head->next == NULL)
            return head;

        ListNode *prev = head, *cur = head->next;
        while (cur) {
            if (cur->val == prev->val) {
                prev->next = cur->next;
                cur = cur->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return head;
    }
};
