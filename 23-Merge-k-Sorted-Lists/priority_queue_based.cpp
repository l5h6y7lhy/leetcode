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

    struct lncomparison
    {
        bool operator() (ListNode* const & lhs, ListNode* const & rhs) const
        {
            return lhs->val > rhs->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, lncomparison> q;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i]) {q.push(lists[i]);}
        }

        ListNode* c;
        ListNode* result = NULL;

        while (!q.empty()) {
            ListNode* curr = q.top();
            q.pop();

            if (!result) {
                result = curr;
                c = curr;
            }
            else {
                c->next = curr;
                c = curr;
            }

            if (curr->next) {
                q.push(curr->next);
            }
        }

        return result;
    }
};
