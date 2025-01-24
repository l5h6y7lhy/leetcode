class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 0, j = 0;
        int y = matrix.size();
        int x = matrix[0].size();

        vector<int> result;

        while (y > 1 && x > 1) {
            for (int p = 0; p < x - 1; p++) {
                result.push_back(matrix[i][j]);
                j++;
            }

            for (int p = 0; p < y - 1; p++) {
                result.push_back(matrix[i][j]);
                i++;
            }

            for (int p = 0; p < x - 1; p++) {
                result.push_back(matrix[i][j]);
                j--;
            }

            for (int p = 0; p < y - 1; p++) {
                result.push_back(matrix[i][j]);
                i--;
            }

            y -= 2;
            x -= 2;
            i++;
            j++;
        }

        if (y == 1) {
            for (int p = 0; p < x; p++) {
                result.push_back(matrix[i][j]);
                j++;
            }

            return result;
        }

        if (x == 1) {
            for (int p = 0; p < y; p++) {
                result.push_back(matrix[i][j]);
                i++;
            }

            return result;
        }

        return result;
    }
};
