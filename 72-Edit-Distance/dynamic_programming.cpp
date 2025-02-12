class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        int r[l1 + 1][l2 + 1];

        for (int i = 0; i < l2 + 1; i++) {r[0][i] = i;}
        for (int i = 1; i < l1 + 1; i++) {r[i][0] = i;}

        for (int i = 1; i < l1 + 1; i++) {
            for (int j = 1; j < l2 + 1; j++) {
                int c = r[i - 1][j] + 1;

                if (r[i][j - 1] + 1 < c) {c = r[i][j - 1] + 1;}

                int c1 = (word1[i - 1] == word2[j - 1]) ? r[i - 1][j - 1] : r[i - 1][j - 1] + 1;

                if (c1 < c) {c = c1;}

                r[i][j] = c;
            }
        }

        return r[l1][l2];
    }
};
