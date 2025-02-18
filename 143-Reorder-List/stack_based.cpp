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
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        stack<ListNode*> r;

        while (curr) {
            r.push(curr);
            curr = curr->next;
        }

        curr = head;
        ListNode *p1, *p2;

        p2 = r.top();
        r.pop();

        while (!r.empty()) {
            p1 = r.top();
            r.pop();

            if (!p2->next && curr->next != p2 && curr->next) {
                ListNode* tmp = curr->next;
                curr->next = p2;
                curr->next->next = tmp;
                p1->next = NULL;
                curr = tmp;
            }

            p2 = p1;
        }

        return;
    }
};
