class Solution {
public:
    struct rectangle {
        int c;
        vector<int> length, height;
    };

    int maximalRectangle(vector<vector<char>>& matrix) {
        maxA = 0;
        m = matrix.size();
        n = matrix[0].size();

        r.resize(m);

        for (int i = 0; i < m; i++) {r[i].resize(n);}

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                if (matrix[i][j] == '0') {
                    r[i][j].c = 0;
                    continue;
                }

                if (j == 0) {
                    r[i][j].c = 1;
                }
                else {
                    r[i][j].c = r[i][j - 1].c + 1;
                }

                if (!i) {
                    (r[i][j].length).push_back(r[i][j].c);
                    (r[i][j].height).push_back(1);
                    if (r[i][j].c > maxA) {maxA = r[i][j].c;}
                    continue;
                }

                bool find = false;

                for (int t = 0; t < (r[i - 1][j].length).size(); t++) {
                    (r[i][j].height).push_back((r[i - 1][j].height)[t] + 1);

                    if (r[i][j].c > (r[i - 1][j].length)[t]) {
                        (r[i][j].length).push_back((r[i - 1][j].length)[t]);
                    }
                    else {
                        (r[i][j].length).push_back(r[i][j].c);
                        find = true;
                    }

                    if ((r[i][j].height).back() * (r[i][j].length).back() > maxA) {
                        maxA = (r[i][j].height).back() * (r[i][j].length).back();
                    }

                    if (find) {break;}
                }

                if (!find) {
                    (r[i][j].length).push_back(r[i][j].c);
                    (r[i][j].height).push_back(1);
                    if (r[i][j].c > maxA) {maxA = r[i][j].c;}
                }
            }
        }

        return maxA;
    }

private:
    int m, n;
    int maxA;
    vector<vector<rectangle>> r;
};
