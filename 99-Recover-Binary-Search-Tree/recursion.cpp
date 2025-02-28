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
    void recoverTree(TreeNode* root) {
        f = false;
        prev = NULL;
        s = NULL;
        b = NULL;

        search(root);

        s->val ^= b->val;
        b->val ^= s->val;
        s->val ^= b->val;

        return;
    }

private:
    bool f;
    TreeNode* prev;
    TreeNode* s;
    TreeNode* b;

    void search(TreeNode*& root) {
        if (!root) {return;}

        search(root->left);

        if (prev) {
            if (root->val < prev->val) {
                if (!s) {
                    s = root;
                    b = prev;
                }
                else {
                    s = root;
                    f = true;
                }
            }
        }

        if (f) {return;}

        prev = root;

        search(root->right);
        return;
    }
};
