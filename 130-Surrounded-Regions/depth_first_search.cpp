class Solution {
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {search(board, 0, i);}
            if (board[m - 1][i] == 'O') {search(board, m - 1, i);}
        }

        for (int j = 1; j < m - 1; j++) {
            if (board[j][0] == 'O') {search(board, j, 0);}
            if (board[j][n - 1] == 'O') {search(board, j, n - 1);}
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'e') {board[i][j] = 'O';}
                else if (board[i][j] == 'O') {board[i][j] = 'X';}
            }
        }

        return;
    }

private:
    int m, n;

    void search(vector<vector<char>>& board, int i, int j) {
        board[i][j] = 'e';

        if (i > 0 && board[i - 1][j] == 'O') {search(board, i - 1, j);}
        if (i < m - 1 && board[i + 1][j] == 'O') {search(board, i + 1, j);}
        if (j > 0 && board[i][j - 1] == 'O') {search(board, i, j - 1);}
        if (j < n - 1 && board[i][j + 1] == 'O') {search(board, i, j + 1);}
        return;
    }
};
