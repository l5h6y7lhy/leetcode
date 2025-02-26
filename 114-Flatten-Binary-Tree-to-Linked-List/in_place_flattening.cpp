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
        while (root) {
            if (!root->left) {
                root = root->right;
                continue;
            }

            TreeNode* tmp = root->left;

            while (tmp->left || tmp->right) {
                if (tmp->right) {tmp = tmp->right;}
                else {tmp = tmp->left;}
            }

            tmp->right = root->right;
            root->right = root->left;
            root->left = NULL;
            root = root->right;
        }

        return;
    }
};
