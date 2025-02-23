/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {return NULL;}

        Node *result;
        result = new Node(node->val);

        v.resize(100, NULL);
        v[node->val - 1] = result;

        search(node, result);

        return result;
    }

private:
    vector<Node*> v;

    void search(Node*& c1, Node*& c2) {
        for (int i = 0; i < (c1->neighbors).size(); i++) {
            Node* tmp;

            if (!v[c1->neighbors[i]->val - 1]) {
                tmp = new Node(c1->neighbors[i]->val);
                v[c1->neighbors[i]->val - 1] = tmp;
                search(c1->neighbors[i], tmp);
            }
            else {
                tmp = v[c1->neighbors[i]->val - 1];
            }

            (c2->neighbors).push_back(tmp);
        }
    }
};
