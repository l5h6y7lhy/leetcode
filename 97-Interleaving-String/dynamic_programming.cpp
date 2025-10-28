class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();

        if (l1 + l2 != s3.size()) {return false;}

        vector<vector<bool>> r(2);
        r[0].resize(l2 + 1);
        r[1].resize(l2 + 1);

        int c = 0;

        for (int j = 0; j <= l1; j++) {
            for (int i = 0; i <= l2; i++) {
                if (!j && !i) {
                    r[c][i] = true;
                    continue;
                }

                if (i && s3[j + i - 1] == s2[i - 1] && r[c][i - 1]) {
                    r[c][i] = true;
                    continue;
                }

                if (j && s3[j + i - 1] == s1[j - 1] && r[1 - c][i]) {
                    r[c][i] = true;
                    continue;
                }

                r[c][i] = false;
            }

            c = 1 - c;
        }

        return r[1 - c][l2];
    }
};
