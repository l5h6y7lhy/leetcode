class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool zr = false;

        for (int i = 0; i < n; i++) {
            zr = zr || (!matrix[0][i]);
        }

        for (int i = 1; i < m; i++) {
            bool zc = false;

            for (int j = 0; j < n; j++) {
                if (!matrix[i][j]) {
                    zc = true;
                    for (int t = 0; t < i; t++) {matrix[t][j] = 0;}
                }
                else if (!matrix[i - 1][j]) {matrix[i][j] = 0;}
            }

            if (zr) {matrix[i - 1].assign(n, 0);}
            zr = zc;
        }

        if (zr) {matrix[m - 1].assign(n, 0);}

        return;
    }
};
