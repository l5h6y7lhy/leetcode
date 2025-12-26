class Solution {
public:
    int minCut(string s) {
        int l = s.size();

        vector<vector<bool>> r;
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

        vector<int> cuts(l + 1, 2001);
        cuts[0] = 0;

        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= i; j++) {
                int n = 1 + cuts[j - 1];

                if (r[j - 1][i - 1] && n < cuts[i]) {
                    cuts[i] = n;
                }
            }
        }

        return cuts[l] - 1;
    }
};
