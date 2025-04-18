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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) {return result;}

        int offset = 300;
        root->val += offset;

        queue<TreeNode*> r;
        r.push(root);

        while (!r.empty()) {
            TreeNode* t = r.front();
            r.pop();

            if (t->val > 100) {
                offset = 300;
                result.push_back((t->val -= offset));
            }

            if (t->right) {
                t->right->val += offset;
                offset *= 0;
                r.push(t->right);
            }

            if (t->left) {
                t->left->val += offset;
                offset *= 0;
                r.push(t->left);
            }
        }

        return result;
    }
};
