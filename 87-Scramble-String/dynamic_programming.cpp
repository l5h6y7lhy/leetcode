class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l = s1.size();
        vector<vector<vector<bool>>> r(l);

        for (int i = 0; i < l; i++) {
            r[i].resize(l);

            for (int j = 0; j < l; j++) {
                r[i][j].resize(l, false);
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                r[0][i][j] = (s1[i] == s2[j]);
            }
        }

        for (int m = 1; m < l; m++) {
            for (int i = 0; i + m < l; i++) {
                for (int j = 0; j + m < l; j++) {
                    for (int c = 0; c < m; c++) {
                        if (r[c][i][j] &&
                            r[m - c - 1][i + c + 1][j + c + 1]) {
                            r[m][i][j] = true;
                        }
                        else if (r[c][i][j + m - c] &&
                                 r[m - c - 1][i + c + 1][j]) {
                            r[m][i][j] = true;
                        }

                        if (r[m][i][j]) {break;}
                    }
                }
            }
        }

        return r[l - 1][0][0];
    }
};