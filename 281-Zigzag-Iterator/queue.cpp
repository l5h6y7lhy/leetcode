class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        bool add = true;
        int p1 = 0, p2 = 0;

        while (add) {
            add = false;

            if (p1 < v1.size()) {
                r.push(v1[p1]);
                p1++;
                add = true;
            }

            if (p2 < v2.size()) {
                r.push(v2[p2]);
                p2++;
                add = true;
            }
        }
    }

    int next() {
        int result = r.front();
        r.pop();
        return result;
    }

    bool hasNext() {
        return (!r.empty());
    }

private:
    queue<int> r;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
