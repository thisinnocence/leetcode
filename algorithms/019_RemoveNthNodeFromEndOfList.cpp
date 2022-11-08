/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<ListNode *> ve;
        while (head) {
            ve.push_back(head);
            head = head->next;
        }
        if (n == 1 && ve.size() == 1) {
            return NULL;
        }
        if (n == ve.size() && ve.size() >= 1) {
            return ve[1];
        }
        if (n == 1) {
            ve[ve.size() - n - 1]->next = NULL;
        } else {
            ve[ve.size() - n - 1]->next = ve[ve.size() - n + 1];
        }
        return ve[0];
    }
};
