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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {return head;}

        int l = 0;
        ListNode* result = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;

        ListNode *h1, *h2, *h3;

        while (1) {
            if (!curr) {break;}
            l++;

            h1 = curr;
            h2 = curr->next;

            while (l < k) {
                if (!h2) {break;}

                h3 = h2->next;
                h2->next = h1;
                h1 = h2;
                h2 = h3;
                l++;
            }

            if (l < k) {break;}

            curr->next = h2;
            if (prev) {prev->next = h1;}
            if (!result) {result = h1;}

            prev = curr;
            curr = curr->next;
            l = 0;
        }

        while (l > 1) {
            h3 = h1->next;
            h1->next = h2;
            h2 = h1;
            h1 = h3;
            l--;
        }

        return result;
    }
};
