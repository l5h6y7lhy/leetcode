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
        unordered_set<int> r;

        while (p) {
            r.insert(p->val);
            p = p->parent;
        }

        while (q) {
            if (r.find(q->val) != r.end()) {break;}
            q = q->parent;
        }

        return q;
    }
};
