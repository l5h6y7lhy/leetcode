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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < preorder.size(); i++) {
            pre[preorder[i]] = i;
            in[inorder[i]]   = i;
        }

        TreeNode* root;
        build(preorder, 0, root, inorder, 0, inorder.size() - 1);

        return root;
    }

private:
    unordered_map<int, int> pre, in;

    int build(vector<int>& preorder, int prel, TreeNode*& r,
               vector<int>& inorder,  int inl,  int inr) {
        r = new TreeNode(preorder[prel]);

        int r_in = in[preorder[prel]];
        int tmp = prel;

        if (r_in > inl) {
            tmp = build(preorder, tmp + 1, r->left, inorder, inl, r_in - 1);
        }

        if (r_in < inr) {
            tmp = build(preorder, tmp + 1, r->right, inorder, r_in + 1, inr);
        }

        return tmp;
    }
};
