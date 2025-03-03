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
        unordered_map<ListNode*, bool> r;

        while (head) {
            r[head] = true;

            if (r[head->next]) {return true;}
            head = head->next;
        }

        return false;
    }
};
