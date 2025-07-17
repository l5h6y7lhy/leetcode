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
        if (!head) {return false;}

        ListNode* slow = head;
        ListNode* fast = head;

        while (1) {
            if (!slow->next) {break;}
            else {slow = slow->next;}

            if (!fast->next) {break;}
            else {fast = fast->next;}

            if (!fast->next) {break;}
            else {fast = fast->next;}

            if (slow == fast) {return true;}
        }

        return false;
    }
};
