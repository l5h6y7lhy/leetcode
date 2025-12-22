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
        queue<Node*> q1, q2;
        int c = 0;

        if (root) {q1.push(root);}

        while (1) {
            queue<Node*>& curr = c ? q2 : q1;
            queue<Node*>& next = c ? q1 : q2;

            if (curr.empty()) {break;}

            while (!curr.empty()) {
                Node* n = curr.front();
                curr.pop();

                if (!curr.empty()) {
                    n->next = curr.front();
                }

                if (n->left)  {next.push(n->left);}
                if (n->right) {next.push(n->right);}
            }

            c = 1 - c;
        }

        return root;
    }
};
