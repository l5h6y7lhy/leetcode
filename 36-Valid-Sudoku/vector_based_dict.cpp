class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        row_r.resize(9);
        col_r.resize(9);
        box_r.resize(9);

        for (int i = 0; i < 9; i++) {
            row_r[i].resize(9);
            col_r[i].resize(9);
            box_r[i].resize(9);
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {continue;}

                int n = board[i][j] - '1';

                if ((++row_r[i][n]) > 1) {return false;}
                if ((++col_r[j][n]) > 1) {return false;}
                if ((++box_r[(i / 3 * 3) + (j / 3)][n]) > 1) {return false;}
            }
        }

        return true;
    }

private:
    vector<vector<int>> row_r;
    vector<vector<int>> col_r;
    vector<vector<int>> box_r;
};
