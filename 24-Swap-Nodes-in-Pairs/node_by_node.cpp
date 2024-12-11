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
    ListNode* swapPairs(ListNode* head) {
        if (!head) {return NULL;}

        ListNode* first  = head;
        ListNode* second = head->next;

        if (!second) {return head;}

        first->next  = second->next;
        second->next = first;
        ListNode* h = second;

        while (1) {
            ListNode* curr = first;

            first = first->next;
            if (!first) {break;}

            second = first->next;
            if (!second) {break;}

            first->next  = second->next;
            second->next = first;
            curr->next   = second;
        }

        return h;
    }
};
