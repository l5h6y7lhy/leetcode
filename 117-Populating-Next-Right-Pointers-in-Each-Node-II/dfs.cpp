/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root, 0);
        return root;
    }

private:
    vector<Node*> r;

    void dfs(Node*& root, int h) {
        if (!root) {return;}

        if (r.size() == h) {r.push_back(NULL);}

        root->next = r[h];
        r[h] = root;

        dfs(root->right, h + 1);
        dfs(root->left, h + 1);

        return;
    }
};
