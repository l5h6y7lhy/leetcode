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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {return false;}

        queue<TreeNode*> q_node;
        q_node.push(root);

        queue<int> q_num;
        q_num.push(root->val);

        while (!q_node.empty()) {
            TreeNode* curr_node = q_node.front();
            q_node.pop();

            int curr_num = q_num.front();
            q_num.pop();

            if (!curr_node->left && !curr_node->right && curr_num == targetSum) {
                return true;
            }

            if (curr_node->left) {
                q_node.push(curr_node->left);
                q_num.push(curr_node->left->val + curr_num);
            }

            if (curr_node->right) {
                q_node.push(curr_node->right);
                q_num.push(curr_node->right->val + curr_num);
            }
        }

        return false;
    }
};
