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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        while (root) {
            r.push(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* root = r.top();
        r.pop();
        int result = root->val;
        root = root->right;

        while (root) {
            r.push(root);
            root = root->left;
        }

        return result;
    }

    bool hasNext() {
        return (!r.empty());
    }

private:
    stack<TreeNode*> r;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
