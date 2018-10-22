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
    bool hasCycle(ListNode *head) {
        if (head == NULL)
            return false;

        ListNode *quick = head, *slow = head;
        while (quick && quick->next) {
            slow = slow->next;
            quick = quick->next->next;
            if (quick == slow) {
                return true;
            }
        }
        return false;
    }
};
