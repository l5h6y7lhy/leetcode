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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> r;

        while (head) {
            if (r.find(head) != r.end()) {return true;}
            r.insert(head);
            head = head->next;
        }

        return false;
    }
};
