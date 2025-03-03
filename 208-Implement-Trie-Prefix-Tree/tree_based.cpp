class Trie {
public:
    struct Tnode {
        bool ending;
        vector<Tnode*> next;
    };

    Trie() {
        create(root);
    }

    void insert(string word) {
        Tnode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';

            if (!curr->next[index]) {create(curr->next[index]);}

            curr = curr->next[index];

            if (i == word.size() - 1) {curr->ending = true;}
        }

        return;
    }

    bool search(string word) {
        Tnode* curr = root;

        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';

            if (!curr->next[index]) {return false;}

            curr = curr->next[index];

            if (i == word.size() - 1 && !curr->ending) {return false;}
        }

        return true;
    }

    bool startsWith(string prefix) {
        Tnode* curr = root;

        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';

            if (!curr->next[index]) {return false;}

            curr = curr->next[index];
        }

        return true;
    }

private:
    Tnode* root;

    void create(Tnode*& root) {
        root = new Tnode();
        (root->next).assign(26, NULL);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
