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
    ListNode* deleteDuplicates(ListNode* head) {
        reorgnize(head);
        return head;
    }

private:
    void reorgnize(ListNode*& head) {
        if (!head) {return;}
        if (!head->next) {return;}

        if (head->val != head->next->val) {
            reorgnize(head->next);
            return;
        }

        ListNode *curr = head->next;

        while (curr && curr->val == head->val) {
            curr = curr->next;
        }

        reorgnize(curr);
        head = curr;
        return;
    }
};
