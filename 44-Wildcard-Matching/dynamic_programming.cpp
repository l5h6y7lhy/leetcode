class Solution {
public:
    bool isMatch(string s, string p) {
        int ls = s.size();
        int lp = p.size();

        vector<vector<bool>> r;

        r.resize(lp + 1);

        for (int i = 0; i <= lp; i++) {
            r[i].resize(ls + 1);
        }

        r[0][0] = true;

        for (int i = 1; i <= ls; i++) {
            r[0][i] = false;
        }

        for (int i = 1; i <= lp; i++) {
            r[i][0] = r[i - 1][0] && (p[i - 1] == '*');
        }

        for (int j = 1; j <= ls; j++) {
            for (int i = 1; i <= lp; i++) {
                bool c = false;

                if (p[i - 1] == '*') {
                    for (int t = j; t >= 0; t--) {
                        if (r[i - 1][t]) {
                            c = true;
                            break;
                        }
                    }
                }
                else {
                    if (p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                        c = r[i - 1][j - 1];
                    }
                }

                r[i][j] = c;
            }
        }

        return r[lp][ls];
    }
};
