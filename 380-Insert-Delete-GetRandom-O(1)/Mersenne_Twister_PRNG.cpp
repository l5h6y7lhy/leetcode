class RandomizedSet {
public:
    RandomizedSet() {
        b.push_back(0);
    }

    bool insert(int val) {
        if (r[val]) {
            return false;
        }

        b.push_back(val);
        r[val] = b.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!r[val]) {
            return false;
        }

        b[r[val]] = b.back();
        r[b.back()] = r[val];
        r[val] = 0;
        b.pop_back();

        return true;
    }

    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(1, b.size() - 1);
        return b[distrib(gen)];
    }

private:
    vector<int> b;
    unordered_map<int, int> r;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
