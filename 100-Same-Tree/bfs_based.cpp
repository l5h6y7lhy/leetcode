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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> rp, rq;
        TreeNode* cp;
        TreeNode* cq;

        rp.push(p);
        rq.push(q);

        while (!rp.empty()) {
            cp = rp.front();
            rp.pop();

            cq = rq.front();
            rq.pop();

            if (!cp && !cq) {continue;}
            if (!cp && cq) {return false;}
            if (cp && !cq) {return false;}
            if (cp->val != cq->val) {return false;}

            rp.push(cp->left);
            rp.push(cp->right);

            rq.push(cq->left);
            rq.push(cq->right);
        }

        return true;
    }
};
