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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_set<ListNode*> r;

        while (headA) {
            r.insert(headA);
            headA = headA->next;
        }

        while (headB) {
            if (r.find(headB) != r.end()) {
                return headB;
            }

            headB = headB->next;
        }

        return NULL;
    }
};
