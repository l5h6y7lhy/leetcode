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
    vector<TreeNode*> generateTrees(int n) {
        return builder(1, n);
    }

private:
    vector<TreeNode*> builder(int l, int r) {
        TreeNode* root;
        vector<TreeNode*> result;

        if (l > r) {
            result.push_back(NULL);
            return result;
        }

        for (int i = 0; i <= r - l; i++) {
            vector<TreeNode*> r1 = builder(l, l - 1 + i);
            vector<TreeNode*> r2 = builder(l + i + 1, r);

            for (int p1 = 0; p1 < r1.size(); p1++) {
                for (int p2 = 0; p2 < r2.size(); p2++) {
                    root = new TreeNode(l + i);
                    root->left = r1[p1];
                    root->right = r2[p2];
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};
