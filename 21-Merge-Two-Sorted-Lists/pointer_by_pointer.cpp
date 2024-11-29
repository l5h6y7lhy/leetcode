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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {return list2;}
        if (!list2) {return list1;}

        ListNode* head = NULL;
        ListNode* curr = NULL;
        ListNode* h1 = list1;
        ListNode* h2 = list2;

        while (h1 && h2) {
            ListNode* t;
            if (h1->val < h2->val) {
                t = h1;
                h1 = h1->next;
            }
            else {
                t = h2;
                h2 = h2->next;
            }

            if (!head) {
                head = t;
                curr = head;
            }
            else {
                curr->next = t;
                curr = curr->next;
            }
        }

        if (!h1) {curr->next = h2;}
        else if (!h2) {curr->next = h1;}

        return head;
    }
};
