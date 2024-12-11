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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        l = 0;
        ListNode* result = NULL;
        ListNode* curr   = NULL;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {
                reo.push_back(lists[i]);
                l++;
            }
        }

        if (!l) {return result;}

        for (int i = l / 2; i > 0; i--) {heapifyDown(i);}

        while (1) {
            ListNode* tmp = reo[0];

            if (!result) {
                curr   = tmp;
                result = tmp;
            }
            else {
                curr->next = tmp;
                curr = curr->next;
            }

            tmp = tmp->next;

            if (tmp) {
                reo[0] = tmp;
            }
            else {
                reo[0] = reo[l - 1];
                l--;
            }

            if (!l) {break;}
            heapifyDown(1);
        }

        return result;
    }

private:
    int l;
    vector<ListNode*> reo;

    void heapifyDown(int index) {
        if (index <= (l/2)) {
            int c = reo[index - 1]->val;
            int left = reo[(2 * index) - 1]->val;
            ListNode* tmp = reo[index - 1];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = reo[2 * index]->val;
            }

            if (left <= right && c > left) {
                reo[index - 1] = reo[(2 * index) - 1];
                reo[(2 * index) - 1] = tmp;
                heapifyDown(2 * index);
            }
            else if (left > right && c > right) {
                reo[index - 1] = reo[2 * index];
                reo[2 * index] = tmp;
                heapifyDown((2 * index) + 1);
            }
        }

        return;
    }
};
