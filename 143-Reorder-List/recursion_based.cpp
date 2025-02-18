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
    void reorderList(ListNode* head) {
        if (!head->next) {return;}

        curr = head;
        swap(head->next);
        return;
    }

private:
    ListNode* curr;

    void swap(ListNode*& parent) {
        if (parent->next) {
            swap(parent->next);
        }

        if (!parent->next && curr->next != parent && curr->next) {
            ListNode* tmp = curr->next;
            curr->next = parent;
            curr->next->next = tmp;
            parent = NULL;
            curr = tmp;
        }

        return;
    }
};
