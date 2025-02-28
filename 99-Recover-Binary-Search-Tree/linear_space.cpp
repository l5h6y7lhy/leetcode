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
    void recoverTree(TreeNode* root) {
        TreeNode *p = root;
        stack<TreeNode*> r;

        TreeNode *prev = NULL, *s = NULL, *b = NULL;

        while (p || !r.empty()) {
            if (!p) {
                p = r.top();
                r.pop();

                if (prev) {
                    if (p->val < prev->val) {
                        if (!s) {
                            s = p;
                            b = prev;
                        }
                        else {
                            s = p;
                            break;
                        }
                    }
                }

                prev = p;
                p = p->right;
            }
            else {
                while (p) {
                    r.push(p);
                    p = p->left;
                }
            }
        }

        s->val ^= b->val;
        b->val ^= s->val;
        s->val ^= b->val;

        return;
    }
};
