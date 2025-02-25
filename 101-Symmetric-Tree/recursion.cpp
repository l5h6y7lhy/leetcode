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
    bool isSymmetric(TreeNode* root) {
        if (!root) {return true;}
        return compare(root->left, root->right);
    }

private:
    bool compare(TreeNode*& t1, TreeNode*& t2) {
        if (!t1 && !t2) {return true;}
        if (!t1 && t2) {return false;}
        if (t1 && !t2) {return false;}
        if (t1->val != t2->val) {return false;}
        if (!compare(t1->left, t2->right)) {return false;}
        if (!compare(t1->right, t2->left)) {return false;}

        return true;
    }
};
