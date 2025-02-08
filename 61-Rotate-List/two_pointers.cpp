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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head || !head->next) {return head;}

        ListNode* c1;
        int c = 1;
        c1 = head;

        while (c1->next) {
            c++;
            c1 = c1->next;
        }

        k = k % c;

        if (!k) {return head;}

        ListNode* c2 = head;
        int t = c - k;
        c = 1;

        while (c < t) {
            c2 = c2->next;
            c++;
        }

        c1->next = head;
        c1 = c2->next;
        c2->next = NULL;

        return c1;
    }
};
