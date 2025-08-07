class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        r.resize(m);

        for (int i = 0; i < m; i++) {
            r[i].resize(n);

            for (int j = 0; j < n; j++) {
                r[i][j].assign(2, 0);
            }
        }

        int num_b = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 || grid[i][j] == 2) {continue;}

                num_b++;
                bfs(grid, i, j);
            }
        }

        int distance = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 || grid[i][j] == 2) {continue;}
                if (r[i][j][0] < num_b) {continue;}

                if (distance < 0 || r[i][j][1] < distance) {
                    distance = r[i][j][1];
                }
            }
        }

        return distance;
    }

private:
    int m, n;
    vector<vector<vector<int>>> r;

    void bfs(vector<vector<int>>& grid, int& y, int& x) {
        vector<vector<bool>> t;
        t.resize(m);
        for (int i = 0; i < m; i++) {t[i].assign(n, false);}

        queue<tuple<int, int, int>> q;
        tuple<int, int, int> curr(y, x, 0);
        q.push(curr);

        while (!q.empty()) {
            curr = q.front();
            q.pop();

            int i = get<0>(curr);
            int j = get<1>(curr);
            int d = get<2>(curr);

            if (i > 0 && grid[i - 1][j] == 0 && !t[i - 1][j]) {
                t[i - 1][j] = true;
                r[i - 1][j][0]++;
                r[i - 1][j][1] += (d + 1);

                tuple<int, int, int> tmp(i - 1, j, d + 1);
                q.push(tmp);
            }

            if (i < m - 1 && grid[i + 1][j] == 0 && !t[i + 1][j]) {
                t[i + 1][j] = true;
                r[i + 1][j][0]++;
                r[i + 1][j][1] += (d + 1);

                tuple<int, int, int> tmp(i + 1, j, d + 1);
                q.push(tmp);
            }

            if (j > 0 && grid[i][j - 1] == 0 && !t[i][j - 1]) {
                t[i][j - 1] = true;
                r[i][j - 1][0]++;
                r[i][j - 1][1] += (d + 1);

                tuple<int, int, int> tmp(i, j - 1, d + 1);
                q.push(tmp);
            }

            if (j < n - 1 && grid[i][j + 1] == 0 && !t[i][j + 1]) {
                t[i][j + 1] = true;
                r[i][j + 1][0]++;
                r[i][j + 1][1] += (d + 1);

                tuple<int, int, int> tmp(i, j + 1, d + 1);
                q.push(tmp);
            }
        }

        return;
    }
};
