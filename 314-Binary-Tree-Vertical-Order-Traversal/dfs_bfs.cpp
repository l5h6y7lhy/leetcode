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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (!root) {return r;}

        lh = 0;
        rh = 0;
        traversal(root, 0);
        r.resize(rh - lh + 1);
        lh = 0 - lh;

        queue<int> col;
        col.push(lh);

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* curr = q.front();
            r[col.front()].push_back(curr->val);

            if (curr->left) {
                q.push(curr->left);
                col.push(col.front() - 1);
            }

            if (curr->right) {
                q.push(curr->right);
                col.push(col.front() + 1);
            }

            q.pop();
            col.pop();
        }

        return r;
    }

private:
    int lh, rh;

    void traversal(TreeNode*& root, int c) {
        if (!root) {return;}

        if (c < lh) {lh = c;}
        if (c > rh) {rh = c;}

        traversal(root->left,  c - 1);
        traversal(root->right, c + 1);
    }
};
