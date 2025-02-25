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
    ListNode* removeElements(ListNode* head, int val) {
        replace(head, val);
        return head;
    }

private:
    void replace(ListNode*& head, int& v) {
        while (head && head->val == v) {
            head = head->next;
        }

        if (!head) {return;}
        replace(head->next, v);
    }
};
