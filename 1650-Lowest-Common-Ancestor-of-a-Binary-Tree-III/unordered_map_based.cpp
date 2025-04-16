/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<int, bool> r;

        while (p) {
            r[p->val] = true;
            p = p->parent;
        }

        while (q) {
            if (r[q->val]) {break;}
            q = q->parent;
        }

        return q;
    }
};
