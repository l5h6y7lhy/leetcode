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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) {return NULL;}

        int total = 0;
        ListNode* curr = head;

        while (curr) {
            total++;
            curr = curr->next;
        }

        curr = head;
        TreeNode* root;
        buildTree(curr, root, total);

        return root;
    }

private:
    void buildTree(ListNode*& curr, TreeNode*& root, int total) {
        if (total < 3) {
            root = new TreeNode(curr->val);
            if (total == 2) {root->right = new TreeNode(curr->next->val);}
            return;
        }

        int half = total / 2;
        ListNode* c = curr;

        for (int i = 0; i < half; i++) {c = c->next;}

        root = new TreeNode(c->val);
        buildTree(curr,    root->left,  half);
        buildTree(c->next, root->right, total - half - 1);
        return;
    }
};
