/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> r;

        while (head) {
            if (r.find(head) != r.end()) {return head;}
            r.insert(head);
            head = head->next;
        }

        return NULL;
    }
};
