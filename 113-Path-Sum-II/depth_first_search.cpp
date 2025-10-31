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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) {return r;}

        sum = 0;
        search(root, targetSum);

        return r;
    }

private:
    int sum;
    vector<int> path;
    vector<vector<int>> r;

    void search(TreeNode*& n, int& targetSum) {
        sum += n->val;
        path.push_back(n->val);

        if (!n->left && !n->right) {
            if (sum == targetSum) {r.push_back(path);}
            path.pop_back();
            sum -= n->val;
            return;
        }

        if (n->left)  {search(n->left,  targetSum);}
        if (n->right) {search(n->right, targetSum);}

        path.pop_back();
        sum -= n->val;

        return;
    }
};
