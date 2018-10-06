#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *head = NULL, **p = &head;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                *p = l1;
                l1 = l1->next;
            } else {
                *p = l2;
                l2 = l2->next;
            }
            p = &((*p)->next);
        }
        *p = (l1 == NULL ? l2 : l1);
        return head;
    }
};

int main() {
    // Input: 1->2->4, 1->3->4
    // Output: 1->1->2->3->4->4

    ListNode node1(1), node2(2), node3(4);
    ListNode *head1 = &node1;
    node1.next = &node2;
    node2.next = &node3;

    ListNode node4(1), node5(3), node6(4);
    ListNode *head2 = &node4;
    node4.next = &node5;
    node5.next = &node6;

    Solution solution;
    ListNode *re = solution.mergeTwoLists(head1, head2);
    while (re) {
        cout << re->val << " ";
        re = re->next;
    }
    cout << endl;
    return 0;
}
