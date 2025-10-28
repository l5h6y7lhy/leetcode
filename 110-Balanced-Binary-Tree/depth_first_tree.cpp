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
    bool isBalanced(TreeNode* root) {
        return (search(root) >= 0);
    }

private:
    int search(TreeNode*& root) {
        if (!root) {return 0;}

        int l = search(root->left);
        if (l < 0) {return -1;}

        int r = search(root->right);
        if (r < 0) {return -1;}

        if (l - r > 1 || r - l > 1) {return -1;}

        return 1 + max(l, r);
    }
};
