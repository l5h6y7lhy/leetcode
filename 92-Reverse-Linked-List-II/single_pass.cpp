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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) {return head;}

        int i = 2;
        ListNode* r1   = NULL;
        ListNode* r2   = head;
        ListNode* prev = head;
        ListNode* curr = head->next;

        while (i <= right) {
            if (i < left) {
                prev = curr;
                curr = curr->next;
            }
            else if (i == left) {
                r1 = prev;
                r2 = curr;
                prev = curr;
                curr = curr->next;
            }
            else if (i <= right) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            i++;
        }

        r2->next = curr;

        if (!r1) {
            return prev;
        }

        r1->next = prev;
        return head;
    }
};