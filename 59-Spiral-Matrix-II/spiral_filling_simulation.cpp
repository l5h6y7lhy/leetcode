class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int i = 0, j = 0;
        int curr = 1;
        int y = n;

        vector<vector<int>> matrix;
        matrix.resize(n);

        for (int p = 0; p < n; p++) {matrix[p].resize(n);}

        while (y > 1) {
            for (int p = 0; p < y - 1; p++) {
                matrix[i][j] = curr;
                curr++;
                j++;
            }

            for (int p = 0; p < y - 1; p++) {
                matrix[i][j] = curr;
                curr++;
                i++;
            }

            for (int p = 0; p < y - 1; p++) {
                matrix[i][j] = curr;
                curr++;
                j--;
            }

            for (int p = 0; p < y - 1; p++) {
                matrix[i][j] = curr;
                curr++;
                i--;
            }

            y -= 2;
            i++;
            j++;
        }

        if (y == 1) {matrix[i][j] = curr;}

        return matrix;
    }
};
