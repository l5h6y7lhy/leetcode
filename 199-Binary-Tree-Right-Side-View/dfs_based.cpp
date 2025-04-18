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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {return result;}

        h = 1;
        traversal(root);
        return result;
    }

private:
    int h;
    vector<int> result;

    void traversal(TreeNode*& root) {
        if (!root) {return;}

        if (h > result.size()) {
            result.push_back(root->val);
        }

        h++;
        traversal(root->right);
        traversal(root->left);
        h--;

        return;
    }
};
