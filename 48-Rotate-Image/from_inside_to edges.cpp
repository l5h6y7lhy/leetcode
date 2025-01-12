class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = matrix.size();
        if (l == 1) {return;}

        int i = (l - 2) / 2;
        int len = 1 + (l % 2);

        while (i >= 0) {
            for (int j = 0; j < len; j++) {
                int t = matrix[i + len - j][i];
                matrix[i + len - j][i] = matrix[i + len][i + len - j];
                matrix[i + len][i + len - j] = matrix[i + j][i + len];
                matrix[i + j][i + len] = matrix[i][i + j];
                matrix[i][i + j] = t;
            }

            i--;
            len += 2;
        }

        return;
    }
};
