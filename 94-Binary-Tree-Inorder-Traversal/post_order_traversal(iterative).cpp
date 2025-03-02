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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> r;
        stack<int> v;
        r.push(root);

        while (!r.empty()) {
            TreeNode* p = r.top();
            r.pop();
            v.push(p->val);

            if (p->left) {r.push(p->left);}
            if (p->right) {r.push(p->right);}
        }

        while (!v.empty()) {
            result.push_back(v.top());
            v.pop();
        }

        return result;
    }
};
