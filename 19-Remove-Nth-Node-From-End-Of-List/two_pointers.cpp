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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *h1 = NULL;
        ListNode* c = head;
        int total = 0;

        while (c) {
            total++;
            c = c->next;

            if (total <= n) {continue;}

            if (!h1) {h1 = head;}
            else {h1 = h1->next;}
        }

        if (!h1) {return head->next;}

        h1->next = h1->next->next;
        return head;
    }
};
