class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> r;
        r.resize(numRows);
        r[0].push_back(1);

        for (int i = 1; i < numRows; i++) {
            r[i].resize(i + 1);

            for (int j = 0; j < i + 1; j++) {
                int t1 = (j - 1 < 0) ? 0 : r[i - 1][j - 1];
                int t2 = (j == i) ? 0 : r[i - 1][j];
                r[i][j] = t1 + t2;
            }
        }

        return r;
    }
};
