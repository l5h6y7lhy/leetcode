class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<pair<int, int>> q1, q2;

        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {continue;}
                else if (grid[i][j] == 1) {fresh++;}
                else {
                    q1.push(pair(i, j));
                }
            }
        }

        int result = 0;

        while (fresh) {
            queue<pair<int, int>>& q = (result % 2) ? q2 : q1;
            queue<pair<int, int>>& c = (result % 2) ? q1 : q2;

            if (q.empty()) {return -1;}

            while (!q.empty()) {
                pair<int, int> o = q.front();
                q.pop();

                int ci = o.first;
                int cj = o.second;

                if (inbound(ci - 1, cj) && grid[ci - 1][cj] == 1) {
                    c.push(pair(ci - 1, cj));
                    grid[ci - 1][cj] = 2;
                    fresh--;
                }

                if (inbound(ci + 1, cj) && grid[ci + 1][cj] == 1) {
                    c.push(pair(ci + 1, cj));
                    grid[ci + 1][cj] = 2;
                    fresh--;
                }

                if (inbound(ci, cj - 1) && grid[ci][cj - 1] == 1) {
                    c.push(pair(ci, cj - 1));
                    grid[ci][cj - 1] = 2;
                    fresh--;
                }

                if (inbound(ci, cj + 1) && grid[ci][cj + 1] == 1) {
                    c.push(pair(ci, cj + 1));
                    grid[ci][cj + 1] = 2;
                    fresh--;
                }
            }

            result++;
        }

        return result;
    }

private:
    int m, n;

    bool inbound(int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n) {return true;}
        return false;
    }
};
