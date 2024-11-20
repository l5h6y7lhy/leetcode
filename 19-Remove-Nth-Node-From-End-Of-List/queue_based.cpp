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
        queue<ListNode *> r;
        r.push(NULL);

        ListNode* c = head;
        int total = 0;

        while (c) {
            total++;

            if (total > n) {r.pop();}
            r.push(c);
            c = c->next;
        }

        ListNode* h1 = r.front();
        r.pop();
        ListNode* h2 = r.front();

        if (!h1) {return h2->next;}

        h1->next = h2->next;
        return head;
    }
};
