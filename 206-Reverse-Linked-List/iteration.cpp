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
    ListNode* reverseList(ListNode* head) {
        if (!head) {return head;}

        ListNode* curr = head->next;
        head->next = NULL;

        while (curr) {
            ListNode* tmp = curr->next;
            curr->next = head;
            head = curr;
            curr = tmp;
        }

        return head;
    }
};
