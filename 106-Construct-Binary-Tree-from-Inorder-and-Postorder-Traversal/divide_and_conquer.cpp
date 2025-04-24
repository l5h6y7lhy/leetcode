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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++) {
            in[inorder[i]] = i;
        }

        TreeNode* root;
        build(postorder, postorder.size() - 1, root, 0, inorder.size() - 1);

        return root;
    }

private:
    unordered_map<int, int> in;

    int build(vector<int>& postorder, int postl, TreeNode*& r, int inl,   int inr) {
        r = new TreeNode(postorder[postl]);

        int r_in = in[postorder[postl]];
        int tmp = postl;

        if (r_in < inr) {
            tmp = build(postorder, tmp - 1, r->right, r_in + 1, inr);
        }

        if (r_in > inl) {
            tmp = build(postorder, tmp - 1, r->left, inl, r_in - 1);
        }

        return tmp;
    }
};
