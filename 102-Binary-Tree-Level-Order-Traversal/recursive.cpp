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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {return r;}
        searchL(root, 1);

        return r;
    }

private:
    vector<vector<int>> r;

    void searchL(TreeNode*& root, int l) {
        if (l > r.size()) {r.resize(l);}
        r[l - 1].push_back(root->val);

        if (root->left) {searchL(root->left, l + 1);}
        if (root->right) {searchL(root->right, l + 1);}
        return;
    }
};
