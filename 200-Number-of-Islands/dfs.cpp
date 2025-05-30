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
                dfs(i, j, grid);
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

    void dfs(int ci, int cj, vector<vector<char>>& grid) {
        grid[ci][cj] = '2';

        if (inbound(ci - 1, cj) && grid[ci - 1][cj] == '1') {
            dfs(ci - 1, cj, grid);
        }

        if (inbound(ci + 1, cj) && grid[ci + 1][cj] == '1') {
            dfs(ci + 1, cj, grid);
        }

        if (inbound(ci, cj - 1) && grid[ci][cj - 1] == '1') {
            dfs(ci, cj - 1, grid);
        }

        if (inbound(ci, cj + 1) && grid[ci][cj + 1] == '1') {
            dfs(ci, cj + 1, grid);
        }

        return;
    }
};
