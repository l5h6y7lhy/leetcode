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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        if (!root) {return result;}

        stack<TreeNode*> r;
        r.push(root);

        while (!r.empty()) {
            TreeNode* p = r.top();
            r.pop();
            result.push_back(p->val);

            if (p->right) {r.push(p->right);}
            if (p->left) {r.push(p->left);}
        }

        return result;
    }
};
