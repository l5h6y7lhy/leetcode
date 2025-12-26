class Solution {
public:
    vector<vector<string>> partition(string s) {
        l = s.size();
        r.resize(l);

        for (int i = 0; i < l; i++) {
            r[i].assign(l, true);
        }

        for (int i = 1; i < l; i++) {
            for (int j = 0; j + i < l; j++) {
                if (s[j] != s[j + i] || !r[j + 1][j + i - 1]) {
                    r[j][j + i] = false;
                }
            }
        }

        search(s, 0);

        return result;
    }

private:
    int l;
    vector<string> curr;
    vector<vector<bool>> r;
    vector<vector<string>> result;

    void search(string& s, int h) {
        if (h == l) {
            result.push_back(curr);
            return;
        }

        string c;

        for (int i = h; i < l; i++) {
            c.push_back(s[i]);

            if (r[h][i]) {
                curr.push_back(c);
                search(s, i + 1);
                curr.pop_back();
            }
        }

        return;
    }
};
