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
    ListNode* swapPairs(ListNode* head) {
        swapTwo(head);
        return head;
    }

private:
    void swapTwo(ListNode*& curr) {
        if (!curr) {return;}

        ListNode* second = curr->next;
        if (!second) {return;}

        curr->next = second->next;
        second->next = curr;

        swapTwo(curr->next);

        curr = second;
        return;
    }
};
