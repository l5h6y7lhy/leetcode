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
    int minDepth(TreeNode* root) {
        if (!root) {return 0;}

        queue<TreeNode*> r1, r2;
        r1.push(root);

        int h = 0;
        bool f = false;

        while (!f) {
            queue<TreeNode*>& curr = (h % 2) ? r2 : r1;
            queue<TreeNode*>& next = (h % 2) ? r1 : r2;

            while (!curr.empty()) {
                TreeNode* n = curr.front();
                curr.pop();

                int children = 0;

                if (n->left) {
                    next.push(n->left);
                    children++;
                }

                if (n->right) {
                    next.push(n->right);
                    children++;
                }

                if (!children) {
                    f = true;
                    break;
                }
            }

            h++;
        }

        return h;
    }
};
