class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {return triangle[0][0];}

        int c_min;

        for (int i = 1; i < triangle.size(); i++) {
            c_min = INT_MAX;

            for (int j = 0; j < triangle[i].size(); j++) {
                int left = (j == 0) ? INT_MAX : triangle[i - 1][j - 1] + triangle[i][j];
                int right = (j == triangle[i].size() - 1) ? INT_MAX : triangle[i - 1][j] + triangle[i][j];
                triangle[i][j] = (left < right) ? left : right;
                if (triangle[i][j] < c_min) {c_min = triangle[i][j];}
            }
        }

        return c_min;
    }
};
