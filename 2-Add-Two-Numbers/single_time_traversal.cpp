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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* prev;
        ListNode* p = new ListNode();
        ListNode* result = p;

        int carry_out = 0;

        while (p1 || p2 || carry_out) {
            int v1 = (p1) ? p1->val : 0;
            int v2 = (p2) ? p2->val : 0;
            carry_out = v1 + v2 + carry_out;

            if (carry_out < 10) {
                p->val = carry_out;
                carry_out = 0;
            }
            else {
                p->val = carry_out % 10;
                carry_out = 1;
            }

            prev = p;
            p->next = new ListNode();
            p = p->next;
            if (p1) {p1 = p1->next;}
            if (p2) {p2 = p2->next;}
        }

        delete p;
        prev->next = NULL;

        return result;
    }
};
