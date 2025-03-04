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
        vector<vector<int>> r;

        if (!root) {return r;}

        vector<TreeNode*> prev, curr;
        prev.push_back(root);

        while (!prev.empty()) {
            vector<int> num;

            for (int i = 0; i < prev.size(); i++) {
                num.push_back(prev[i]->val);
                if (prev[i]->left) {curr.push_back(prev[i]->left);}
                if (prev[i]->right) {curr.push_back(prev[i]->right);}
            }

            r.push_back(num);
            prev = curr;
            curr.clear();
        }

        return r;
    }
};
