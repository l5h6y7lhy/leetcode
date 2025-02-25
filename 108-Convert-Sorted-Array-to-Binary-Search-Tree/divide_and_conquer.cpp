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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root;
        create(nums, 0, nums.size() - 1, root);
        return root;
    }

private:
    void create(vector<int>& nums, int l, int r, TreeNode*& root) {
        if (r < l) {return;}

        int m = (l + r) / 2;

        root = new TreeNode(nums[m]);

        create(nums, l, m - 1, root->left);
        create(nums, m + 1, r, root->right);
        return;
    }
};
