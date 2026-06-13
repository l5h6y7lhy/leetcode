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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {

        new_root = NULL;
        if (!root) {return new_root;}

        adjust(NULL, root);
        return new_root;
    }

private:
    TreeNode* new_root;

    void adjust(TreeNode* parent, TreeNode*& curr) {

        if (!curr->left) {
            new_root = curr;
        }
        else {
            adjust(curr, curr->left);
        }

        if (parent) {
            curr->left = parent->right;
            curr->right = parent;
        }
        else {
            curr->left = parent;
            curr->right = parent;
        }
    }
};
