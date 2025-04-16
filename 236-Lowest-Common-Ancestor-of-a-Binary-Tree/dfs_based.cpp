/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        found = 0;
        search(root, p, q);
        return r;
    }

private:
    int found;
    TreeNode* r;

    bool search(TreeNode*& root, TreeNode*& p, TreeNode*& q) {
        if (found == 2) {return false;}
        if (!root) {return false;}

        int local = 0;

        if (root->val == p->val || root->val == q->val) {
            found++;
            local++;
        }

        if (search(root->left, p, q)) {
            local++;
        }

        if (local == 2) {
            r = root;
            return true;
        }

        if (search(root->right, p, q)) {
            local++;
        }

        if (local == 2) {
            r = root;
            return true;
        }

        return (local > 0);
    }
};
