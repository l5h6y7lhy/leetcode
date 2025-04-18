class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {return -1;}

        r.resize(n);
        for (int i = 0; i < n; i++) {r[i].assign(n, -1);}
        r[0][0] = 1;

        x.push(0);
        y.push(0);

        while (!x.empty()) {
            int cx = x.front();
            x.pop();

            int cy = y.front();
            y.pop();

            bool found = check(cx - 1, cy - 1, r[cx][cy], grid);
            found = found || check(cx - 1, cy, r[cx][cy], grid);
            found = found || check(cx - 1, cy + 1, r[cx][cy], grid);
            found = found || check(cx, cy - 1, r[cx][cy], grid);
            found = found || check(cx, cy, r[cx][cy], grid);
            found = found || check(cx, cy + 1, r[cx][cy], grid);
            found = found || check(cx + 1, cy - 1, r[cx][cy], grid);
            found = found || check(cx + 1, cy, r[cx][cy], grid);
            found = found || check(cx + 1, cy + 1, r[cx][cy], grid);

            if (found) {return r[n - 1][n - 1];}
        }

        return r[n - 1][n - 1];
    }

private:
    int n;
    vector<vector<int>> r;
    queue<int> x, y;

    bool check(int cx, int cy, int& pl, vector<vector<int>>& grid) {
        if (cx < 0 || cx >= n || cy < 0 || cy >= n) {return false;}

        if (grid[cx][cy] == 0 && r[cx][cy] < 0) {
            r[cx][cy] = pl + 1;
            x.push(cx);
            y.push(cy);

            if (cx == n - 1 && cy == n - 1) {return true;}
        }

        return false;
    }
};
