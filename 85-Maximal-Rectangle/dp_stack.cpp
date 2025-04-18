class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        maxA = 0;
        m = matrix.size();
        n = matrix[0].size();

        heights.assign(m, 0);

        for (int j = 0; j < n; j++) {
            stack<int> r;
            vector<int> result(m, 0);

            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '1') {
                    heights[i]++;
                }
                else {
                    heights[i] = 0;
                }

                while (!r.empty()) {
                    int curr = r.top();

                    if (heights[curr] < heights[i]) {
                        break;
                    }

                    result[curr] += heights[curr] * (i - curr - 1);
                    r.pop();
                }

                int lb = r.empty() ? -1 : r.top();
                result[i] += heights[i] * (i - lb);
                r.push(i);
            }

            int rb = r.top();
            r.pop();

            while (!r.empty()) {
                int lo = r.top();
                result[lo] += heights[lo] * (rb - lo);
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
    vector<int> heights;
};
