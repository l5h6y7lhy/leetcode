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
        TreeNode* root;
        r.resize(n + 2);

        for (int i = 0; i < n + 2; i++) {r[i].resize(n + 2);}

        for (int i = 1; i < n + 2; i++) {r[i][i - 1].push_back(NULL);}

        for (int i = 1; i < n + 1; i++) {
            root = new TreeNode(i);
            r[i][i].push_back(root);
        }

        for (int j = 1; j < n + 1; j++) {
            for (int i = j - 1; i > 0; i--) {
                for (int c = 0; c <= j - i; c++) {
                    for (int p1 = 0; p1 < r[i][i - 1 + c].size(); p1++) {
                        for (int p2 = 0; p2 < r[i + c + 1][j].size(); p2++) {
                            root = new TreeNode(i + c);
                            root->left = r[i][i - 1 + c][p1];
                            root->right = r[i + c + 1][j][p2];
                            r[i][j].push_back(root);
                        }
                    }
                }
            }
        }

        return r[1][n];
    }

private:
    vector<vector<vector<TreeNode*>>> r;
};
