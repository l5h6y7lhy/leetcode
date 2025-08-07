class LRUCache {
public:
    struct LRUnode {
        int val, key;
        LRUnode *prev, *next;

        LRUnode(int v, int k, LRUnode* p, LRUnode* n) {
            val = v;
            key = k;
            prev = p;
            next = n;
        }
    };

    LRUCache(int capacity) {
        count = capacity;
        head = NULL;
        tail = NULL;
    }

    int get(int key) {
        if (!r[key]) {return -1;}
        modify(key);
        return r[key]->val;
    }

    void put(int key, int value) {
        if (r[key]) {
            modify(key);
            r[key]->val = value;
            return;
        }

        if (count > 0) {
            LRUnode* c = new LRUnode(value, key, tail, NULL);
            count--;
            buildTail(c);
            r[key] = c;
        }
        else {
            r[head->key] = NULL;
            head->key = key;
            head->val = value;
            r[key] = head;
            modify(key);
        }

        return;
    }

private:
    int count;
    LRUnode* head;
    LRUnode* tail;
    unordered_map<int, LRUnode*> r;

    void modify(int& key) {
        LRUnode* c = r[key];

        LRUnode* n = c->next;
        if (!n) {return;}

        LRUnode* p = c->prev;

        if (p) {p->next = c->next;}
        else {head = c->next;}

        n->prev = p;
        buildTail(c);
    }

    void buildTail(LRUnode*& c) {
        if (!head) {
            head = c;
            tail = c;
            return;
        }

        tail->next = c;
        c->prev = tail;
        c->next = NULL;
        tail = c;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
