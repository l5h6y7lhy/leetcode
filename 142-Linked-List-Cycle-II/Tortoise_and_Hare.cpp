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
        if (!head) {return head;}

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
