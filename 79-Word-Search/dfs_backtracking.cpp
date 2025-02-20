class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        if (m * n < word.size()) {return false;}

        r.resize(m);

        for (int i = 0; i < m; i++) {
            r[i].assign(n, false);
        }

        int curr = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, word, curr, i, j)) {return true;}
            }
        }

        return false;
    }

private:
    int m;
    int n;
    vector<vector<bool>> r;

    bool search(vector<vector<char>>& board, string& word, int& curr, int i, int j) {
        if (r[i][j] || board[i][j] != word[curr]) {return false;}

        r[i][j] = true;
        curr++;

        if (curr == word.size()) {return true;}

        if (i - 1 >= 0 && search(board, word, curr, i - 1, j)) {
            return true;
        }

        if (i + 1 < m && search(board, word, curr, i + 1, j)) {
            return true;
        }

        if (j - 1 >= 0 && search(board, word, curr, i, j - 1)) {
            return true;
        }

        if (j + 1 < n && search(board, word, curr, i, j + 1)) {
            return true;
        }

        r[i][j] = false;
        curr--;
        return false;
    }
};
