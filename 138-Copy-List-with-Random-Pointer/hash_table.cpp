/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {return NULL;}

        Node* c_head = new Node(head->val);

        unordered_map<Node*, Node*> r;
        r[head] = c_head;

        Node *prev = c_head, *curr = head->next;

        while (curr) {
            Node* tmp = new Node(curr->val);
            r[curr] = tmp;
            prev->next = tmp;
            prev = tmp;
            curr = curr->next;
        }

        prev = head;
        curr = c_head;

        while (prev) {
            if (prev->random) {
                curr->random = r[prev->random];
            }

            prev = prev->next;
            curr = curr->next;
        }

        return c_head;
    }
};
