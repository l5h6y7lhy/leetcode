class Solution {
public:
    int numTrees(int n) {
        vector<int> r(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            r[i] = 0;

            for (int j = 0;  j < i; j++) {
                r[i] += (r[j] * r[i - 1 - j]);
            }
        }

        return r[n];
    }
};
