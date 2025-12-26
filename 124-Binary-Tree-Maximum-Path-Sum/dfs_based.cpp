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
    int maxPathSum(TreeNode* root) {
        result = INT_MIN;
        dfs(root);
        return result;
    }

private:
    int result;

    int dfs(TreeNode*& root) {
        if (!root) {return 0;}

        int l = max(dfs(root->left),  0);
        int r = max(dfs(root->right), 0);

        result = max(result, root->val + l + r);
        int curr = root->val + max(l, r);

        return max(0, curr);
    }
};
