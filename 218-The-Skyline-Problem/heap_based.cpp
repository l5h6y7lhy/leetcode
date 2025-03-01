class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        l = 0;
        bool f;

        t1.resize(2);
        t2.resize(3);

        for (int i = 0; i < buildings.size(); i++) {
            if (!l) {
                r.push_back(buildings[i]);
                l++;
                continue;
            }

            f = false;
            curr.clear();
            t2 = buildings[i];

            while (l > 0) {
                if (t2[0] > r[0][1] ||
                   (t2[0] == r[0][1] && t2[2] > r[0][2])) {
                    t1[0] = r[0][0];
                    t1[1] = r[0][2];
                    result.push_back(t1);
                    modify();
                }
                else if (t2[0] == r[0][1]) {
                    if (t2[2] == r[0][2]) {
                        f = true;
                        t2[0] = r[0][0];
                        curr.push_back(t2);
                        modify();
                        prev[1] = t2[1];
                    }
                    else {
                        curr.push_back(r[0]);
                        modify();
                    }
                }
                else if (t2[2] < r[0][2]) {
                    if (t2[1] <= r[0][1]) {break;}
                    curr.push_back(r[0]);
                    modify();
                }
                else if (t2[2] == r[0][2]) {
                    if (t2[1] <= r[0][1]) {break;}
                    f = true;
                    t2[0] = r[0][0];
                    curr.push_back(t2);
                    modify();
                    prev[1] = t2[1];
                }
                else {
                    if (t2[0] > r[0][0]) {
                        t1[0] = r[0][0];
                        t1[1] = r[0][2];
                        result.push_back(t1);
                    }

                    if (t2[0] < r[0][0] && !f) {t2[0] = r[0][0];}

                    if (!f) {
                        curr.push_back(t2);
                        f = true;
                    }

                    if (t2[1] > r[0][1]) {
                        modify();
                    }
                    else {
                        if (t2[1] < r[0][1]) {
                            t2[0] = t2[1];
                            t2[1] = r[0][1];
                            t2[2] = r[0][2];
                            curr.push_back(t2);
                        }
                        modify();
                        break;
                    }
                }
            }

            if (!l) {
                if (t2[0] > prev[1]) {
                    t1[0] = prev[1];
                    t1[1] = 0;
                    result.push_back(t1);
                    curr.push_back(t2);
                }
                else if (t2[0] == prev[1] && t2[2] > prev[2]) {
                    curr.push_back(t2);
                }
                else if (t2[1] > prev[1] && t2[2] < prev[2]) {
                    t2[0] = prev[1];
                    curr.push_back(t2);
                }
            }

            for (int j = 0; j < curr.size(); j++) {
                r.push_back(curr[j]);
                l++;
                heapifyUp(l);
            }
        }

        while (l > 0) {
            t1[0] = r[0][0];
            t1[1] = r[0][2];
            result.push_back(t1);
            modify();
        }

        t1[0] = prev[1];
        t1[1] = 0;
        result.push_back(t1);

        return result;
    }

private:
    int l;
    vector<int> t1, t2, prev;
    vector<vector<int>> result, r, curr;

    void modify() {
        prev = r[0];
        r[0] = r.back();
        r.pop_back();
        l--;
        heapifyDown(1);
    }

    void heapifyUp(int index) {
        if (index > 1) {
            int parent = index / 2;

            if (r[index - 1][0] < r[parent - 1][0]) {
                vector<int> tmp = r[index - 1];
                r[index - 1] = r[parent - 1];
                r[parent - 1] = tmp;
                heapifyUp(parent);
            }
        }
    }

    void heapifyDown(int index) {
        if (index <= (l/2)) {
            int c = r[index - 1][0];
            int left = r[(2 * index) - 1][0];
            int right = INT_MAX;

            if ((2 * index) + 1 <= l) {
                right = r[2 * index][0];
            }

            if (left <= right && c > left) {
                vector<int> tmp = r[index - 1];
                r[index - 1] = r[(2 * index) - 1];
                r[(2 * index) - 1] = tmp;
                heapifyDown(2 * index);
            }
            else if (left > right && c > right) {
                vector<int> tmp = r[index - 1];
                r[index - 1] = r[2 * index];
                r[2 * index] = tmp;
                heapifyDown((2 * index) + 1);
            }
        }

        return;
    }
};
