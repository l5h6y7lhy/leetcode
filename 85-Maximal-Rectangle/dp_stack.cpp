class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        maxA = 0;
        m = matrix.size();
        n = matrix[0].size();

        heights.resize(m);
        for (int i = 0; i < m; i++) {heights[i].resize(n);}

        for (int j = 0; j < n; j++) {
            stack<int> r;
            vector<int> result(m, 0);

            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '0') {
                    heights[i][j] = 0;
                }
                else if (j == 0) {
                    heights[i][j] = 1;
                }
                else {
                    heights[i][j] = heights[i][j - 1] + 1;
                }

                while (!r.empty()) {
                    int curr = r.top();

                    if (heights[curr][j] <= heights[i][j]) {
                        break;
                    }

                    result[curr] += heights[curr][j] * (i - curr - 1);
                    r.pop();
                }

                int lb = r.empty() ? -1 : r.top();
                result[i] += heights[i][j] * (i - lb);
                r.push(i);
            }

            int rb = r.top();
            r.pop();

            while (!r.empty()) {
                int lo = r.top();
                result[lo] += heights[lo][j] * (rb - lo);
                r.pop();
            }

            for (int i = 0; i < m; i++) {
                if (result[i] > maxA) {maxA = result[i];}
            }
        }

        return maxA;
    }

private:
    int m, n;
    int maxA;
    vector<vector<int>> heights;
};
