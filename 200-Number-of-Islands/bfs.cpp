class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        m = grid.size();
        n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0' || grid[i][j] == '2') {continue;}

                result++;
                bfs(i, j, grid);
            }
        }

        return result;
    }

private:
    int m, n;

    bool inbound(int i, int j) {
        if (i >= 0 && i < m && j >= 0 && j < n) {return true;}
        return false;
    }

    void bfs(int& sy, int& sx, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push(pair(sy, sx));
        grid[sy][sx] = '2';

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();

            int ci = p.first;
            int cj = p.second;

            if (inbound(ci - 1, cj) && grid[ci - 1][cj] == '1') {
                q.push(pair(ci - 1, cj));
                grid[ci - 1][cj] = '2';
            }

            if (inbound(ci + 1, cj) && grid[ci + 1][cj] == '1') {
                q.push(pair(ci + 1, cj));
                grid[ci + 1][cj] = '2';
            }

            if (inbound(ci, cj - 1) && grid[ci][cj - 1] == '1') {
                q.push(pair(ci, cj - 1));
                grid[ci][cj - 1] = '2';
            }

            if (inbound(ci, cj + 1) && grid[ci][cj + 1] == '1') {
                q.push(pair(ci, cj + 1));
                grid[ci][cj + 1] = '2';
            }
        }

        return;
    }
};
