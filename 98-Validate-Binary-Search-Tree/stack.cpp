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
    bool isValidBST(TreeNode* root) {
        int prev;
        int f = false;
        stack<TreeNode*> r;
        TreeNode *p = root;

        while (p || !r.empty()) {
            if (!p) {
                p = r.top();
                r.pop();

                if (f && p->val <= prev) {return false;}
                f = true;
                prev = p->val;

                p = p->right;
            }
            else {
                while (p) {
                    r.push(p);
                    p = p->left;
                }
            }
        }

        return true;
    }
};
