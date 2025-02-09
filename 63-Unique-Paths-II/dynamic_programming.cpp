class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m - 1][n - 1] || obstacleGrid[0][0]) {return 0;}

        bool stone = false;

        for (int i = 0; i < n; i++) {
            if (obstacleGrid[0][i]) {
                stone = true;
                obstacleGrid[0][i] = 0;
            }
            else if (stone) {obstacleGrid[0][i] = 0;}
            else {obstacleGrid[0][i] = 1;}
        }

        stone = false;

        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0]) {
                stone = true;
                obstacleGrid[i][0] = 0;
            }
            else if (stone) {obstacleGrid[i][0] = 0;}
            else {obstacleGrid[i][0] = 1;}
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = 0;
                }
                else {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                }
            }
        }

        return obstacleGrid[m - 1][n - 1];
    }
};
