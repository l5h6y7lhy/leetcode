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

        int c = 0;
        ListNode* curr = head->next;
        stack<ListNode*> s1, s2;

        while (curr) {
            c++;
            s1.push(curr);
            curr = curr->next;
        }

        for (int i = 0; i < c / 2; i++) {
            s2.push(s1.top());
            s1.pop();
        }

        if (s1.size() > s2.size()) {
            curr = s1.top();
            s1.pop();
            curr->next = NULL;
        }
        else {curr = NULL;}

        while (!s1.empty()) {
            ListNode* p1 = s1.top();
            s1.pop();
            ListNode* p2 = s2.top();
            s2.pop();
            p2->next = p1;
            p1->next = curr;
            curr = p2;
        }

        head->next = curr;
        return;
    }
};
