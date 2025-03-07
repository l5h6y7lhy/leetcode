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
    int maxDepth(TreeNode* root) {
        return findD(root);
    }

private:
    int findD(TreeNode*& root) {
        if (!root) {return 0;}

        int l = findD(root->left);
        int r = findD(root->right);

        if (l > r) {return l + 1;}
        return r + 1;
    }
};
