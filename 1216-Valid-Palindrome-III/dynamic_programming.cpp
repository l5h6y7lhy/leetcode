class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int l = s.size();

        vector<vector<int>> r(2);
        r[0].assign(l, 0);
        r[1].assign(l, 0);

        for (int i = 0; i < l - 1; i++) {
            if (s[i] != s[i + 1]) {r[1][i] = 1;}
        }

        int c = 0;

        for (int i = 2; i < l; i++) {
            for (int j = 0; j + i < l; j++) {
                if (s[j] == s[j + i]) {r[c][j] = r[c][j + 1];}
                else {
                    r[c][j] = 1 + std::min(r[1 - c][j], r[1 - c][j + 1]);
                }
            }

            c = 1 - c;
        }

        c = 1 - c;
        return (r[c][0] <= k);
    }
};
