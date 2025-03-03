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
    ListNode* partition(ListNode* head, int x) {
        ListNode* s = NULL;
        ListNode* b = NULL;
        ListNode* b_head = NULL;
        ListNode* r = NULL;
        ListNode *n;

        while (head) {
            n = head->next;

            if (head->val < x) {
                if (!s) {
                    s = head;
                    s->next = b_head;
                    r = s;
                }
                else {
                    s->next = head;
                    head->next = b_head;
                    s = s->next;
                }
            }
            else {
                if (!r) {
                    b_head = head;
                    b = head;
                    b->next = NULL;
                    r = b_head;
                }
                else if (!b) {
                    s->next = head;
                    b_head = head;
                    b = head;
                    b->next = NULL;
                }
                else {
                    b->next = head;
                    b = b->next;
                    b->next = NULL;
                }
            }

            head = n;
        }

        return r;
    }
};
