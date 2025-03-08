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
        int c = 0;

        while (head) {
            c++;
            ListNode* tmp = head;
            int t = c;

            for (int i = 0; i < c; i++) {
                tmp = tmp->next;

                if (!tmp) {return false;}
                if (tmp == head) {return true;}

                t++;
            }

            c = t;
            head = tmp;
        }

        return false;
    }
};
