class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        m = matrix.size();
        n = matrix[0].size();

        return findV(matrix, target, 0, m - 1);
    }

private:
    int m, n;

    bool findA(vector<int>& vec, int& target, int l, int r) {
        if (r < l) {return false;}
        if (l == r) {return (target == vec[l]);}

        int md = (l + r) / 2;

        if (target == vec[md]) {return true;}
        else if (target < vec[md]) {
            return findA(vec, target, l, md - 1);
        }
        else {
            return findA(vec, target, md + 1, r);
        }
    }

    bool findV(vector<vector<int>>& matrix, int& target, int l, int r) {
        if (r < l) {return false;}
        if (l == r) {return findA(matrix[l], target, 0, n - 1);}

        int md = (l + r) / 2;

        if (target < matrix[md][0]) {
            return findV(matrix, target, l, md - 1);
        }
        else if (target > matrix[md][n - 1]) {
            return findV(matrix, target, md + 1, r);
        }
        else {
            return findA(matrix[md], target, 0, n - 1);
        }
    }
};
