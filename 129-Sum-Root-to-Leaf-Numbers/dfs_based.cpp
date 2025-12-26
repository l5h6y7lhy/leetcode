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
    int sumNumbers(TreeNode* root) {
        total = 0;
        dfs(root);
        return total;
    }

private:
    int total;

    int dfs(TreeNode*& root) {
        if (!root->left && !root->right) {
            total += root->val;
            return 1;
        }

        int sum = 0;

        if (root->left)  {sum += dfs(root->left);}
        if (root->right) {sum += dfs(root->right);}

        sum *= 10;
        total += (sum * root->val);

        return sum;
    }
};
