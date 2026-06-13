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

        ListNode* Aend = headA;

        while (Aend->next) {
            Aend = Aend->next;
        }

        Aend->next = headB;
        ListNode* result = detectCycle(headA);
        Aend->next = NULL;

        return result;
    }

private:
    ListNode *detectCycle(ListNode*& head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (1) {
            if (!fast->next) {return NULL;}
            else {fast = fast->next;}

            if (!fast->next) {return NULL;}
            else {fast = fast->next;}

            slow = slow->next;

            if (slow == fast) {break;}
        }

        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};
