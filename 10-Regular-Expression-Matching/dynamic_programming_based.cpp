class Solution {
public:
    bool isMatch(string s, string p) {
        int pl = p.size();
        int sl = s.size();
        vector<vector<bool>> r;

        r.resize(pl + 1);

        for (int i = 0; i < pl + 1; i++) {r[i].resize(sl + 1);}

        r[0][0] = true;
        for (int i = 1; i <= s.size(); i++) {r[0][i] = false;}

        for (int i = 1; i <= p.size(); i++) {
            if (p[i-1] == '*') {r[i][0] = r[i-2][0];}
            else {r[i][0] = false;}
        }

        for (int i = 1; i <= p.size(); i++) {
            for (int j = 1; j <= s.size(); j++) {
                if (p[i-1] == s[j-1] || p[i-1] == '.') {
                    r[i][j] = r[i-1][j-1];
                    continue;
                }
                else if (p[i-1] == '*') {
                    if (r[i-1][j] || r[i-2][j]) {
                        r[i][j] = true;
                        continue;
                    }
                    else if (r[i][j-1] && (p[i-2] == s[j-1] || p[i-2] == '.')) {
                        r[i][j] = true;
                        continue;
                    }
                }

                r[i][j] = false;
            }
        }

        return r[p.size()][s.size()];
    }
};
