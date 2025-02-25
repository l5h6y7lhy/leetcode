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
    ListNode* sortList(ListNode* head) {
        int token = 1;

        while (1) {
            int half = 0;
            ListNode* t1 = head;
            ListNode* prev = NULL;

            while (t1) {
                int c = 0;
                half++;
                ListNode *t2 = t1;

                while (c < token && t2) {
                    t2 = t2->next;
                    c++;
                }

                if (!t2) {
                    break;
                }

                c = 0;
                int c2 = 0;

                while (c < token && c2 < token && t2) {
                    if (t1->val <= t2->val) {
                        if (!prev) {head = t1;}
                        else {prev->next = t1;}

                        c++;
                        prev = t1;
                        t1 = t1->next;
                    }
                    else {
                        if (!prev) {head = t2;}
                        else {prev->next = t2;}

                        c2++;
                        prev = t2;
                        t2 = t2->next;
                    }
                }

                if (c2 == token || !t2) {
                    ListNode* tmp = t2;
                    prev->next = t1;
                    prev = t1;

                    while (c < token - 1) {
                        prev = prev->next;
                        c++;
                    }

                    prev->next = tmp;
                    t1 = tmp;
                }
                else {
                    prev->next = t2;

                    while (c2 < token - 1 && t2->next) {
                        t2 = t2->next;
                        c2++;
                    }

                    prev = t2;
                    t1 = prev->next;
                }
            }

            if (half <= 1) {break;}
            token *= 2;
        }

        return head;
    }
};
