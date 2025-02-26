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
    void flatten(TreeNode* root) {
        if (!root) {return;}

        record(root);

        for (int i = r.size() - 1; i >= 0; i--) {
            r[i]->left = NULL;
            r[i]->right = (i == r.size() - 1) ? NULL : r[i + 1];
        }

        return;
    }

private:
    vector<TreeNode*> r;

    void record(TreeNode*& root) {
        if (!root) {return;}
        r.push_back(root);
        record(root->left);
        record(root->right);
        return;
    }
};
