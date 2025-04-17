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
    int rangeSumBST(TreeNode* root, int low, int high) {
        result = 0;
        traversal(root, low, high);
        return result;
    }

private:
    int result;

    void traversal(TreeNode*& root, int& low, int& high) {
        if (!root) {return;}

        if (root->val >= low && root->val <= high) {
            result += root->val;
        }

        if (root->val > low) {traversal(root->left, low, high);}
        if (root->val < high) {traversal(root->right, low, high);}
    }
};
