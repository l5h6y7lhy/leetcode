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

        queue<Node*> q1, q2;
        q1.push(node);

        Node *result;
        result = new Node(node->val);
        q2.push(result);

        vector<Node*> v(100, NULL);
        v[node->val - 1] = result;

        while (!q1.empty()) {
            Node *c1 = q1.front();
            q1.pop();

            Node *c2 = q2.front();
            q2.pop();

            for (int i = 0; i < (c1->neighbors).size(); i++) {
                Node* tmp;

                if (!v[c1->neighbors[i]->val - 1]) {
                    tmp = new Node(c1->neighbors[i]->val);
                    q1.push(c1->neighbors[i]);
                    q2.push(tmp);
                    v[c1->neighbors[i]->val - 1] = tmp;
                }
                else {
                    tmp = v[c1->neighbors[i]->val - 1];
                }

                (c2->neighbors).push_back(tmp);
            }
        }

        return result;
    }
};
