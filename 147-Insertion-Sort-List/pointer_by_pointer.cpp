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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* result = NULL;

        while (head) {
            ListNode* tmp = head->next;
            insertion(result, head);
            head = tmp;
        }

        return result;
    }

private:
    void insertion(ListNode*& c, ListNode*& t) {
        if (!c || t->val <= c->val) {
            ListNode* tmp = c;
            c = t;
            t->next = tmp;
            return;
        }

        insertion(c->next, t);
        return;
    }
};
