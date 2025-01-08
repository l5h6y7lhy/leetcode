class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
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

                row_r[i][n] = true;
                col_r[j][n] = true;
                box_r[(i / 3 * 3) + (j / 3)][n] = true;
            }
        }

        result = false;
        int x = 0, y = 0;
        fill(board, y, x);
        return;
    }

private:
    bool result;
    vector<vector<bool>> row_r;
    vector<vector<bool>> col_r;
    vector<vector<bool>> box_r;

    void fill(vector<vector<char>>& board, int& y, int& x) {
        int lx = x;
        int ly = y;

        while (ly < 9) {
            if (board[ly][lx] != '.') {
                lx++;
                ly += (lx / 9);
                lx = lx % 9;
                continue;
            }
            break;
        }

        if (ly == 9) {
            result = true;
            return;
        }

        int ox = lx;
        int oy = ly;

        for (int n = 0; n < 9; n++) {
            if (row_r[ly][n]) {continue;}
            if (col_r[lx][n]) {continue;}
            if (box_r[(ly / 3 * 3) + (lx / 3)][n]) {continue;}

            row_r[ly][n] = true;
            col_r[lx][n] = true;
            box_r[(ly / 3 * 3) + (lx / 3)][n] = true;

            lx++;
            ly += (lx / 9);
            lx = lx % 9;
            fill(board, ly, lx);

            if (result) {
                board[oy][ox] = '1' + n;
                return;
            }

            ly = oy;
            lx = ox;
            row_r[ly][n] = false;
            col_r[lx][n] = false;
            box_r[(ly / 3 * 3) + (lx / 3)][n] = false;
        }

        return;
    }
};
