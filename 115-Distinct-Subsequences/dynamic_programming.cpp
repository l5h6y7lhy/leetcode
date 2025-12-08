class Solution {
public:
    int numDistinct(string s, string t) {
        int ls = s.size();
        int lt = t.size();

        if (ls < lt) {return 0;}

        vector<vector<long>> r(2);
        r[0].resize(ls);
        r[1].resize(ls);

        int c = 0;
        int total = 0;

        for (int i = 0; i < ls; i++) {
            if (s[i] == t[0]) {total++;}
            r[c][i] = total;
        }

        for (int j = 1; j < lt; j++) {
            total = 0;
            c = 1 - c;

            for (int i = j; i < ls; i++) {
                if (s[i] == t[j]) {
                    total += r[1 - c][i - 1];
                }

                r[c][i] = total;
            }
        }

        return ((int) r[c][ls - 1]);
    }
};
