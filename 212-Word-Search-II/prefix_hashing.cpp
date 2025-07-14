class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string curr = "";

            for (int j = 0; j < words[i].size(); j++) {
                curr += words[i][j];
                pre[curr]++;
            }

            com.insert(curr);
        }

        m = board.size();
        n = board[0].size();

        r.resize(m);

        for (int i = 0; i < m; i++) {
            r[i].assign(n, false);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                search(board, i, j);
            }
        }

        return result;
    }

private:
    int m;
    int n;
    string c;
    vector<vector<bool>> r;
    vector<string> result;
    unordered_set<string> com;
    unordered_map<string, int> pre;

    int search(vector<vector<char>>& board, int i, int j) {
        r[i][j] = true;
        c += board[i][j];

        int total = 0;

        if (pre[c] == 0) {
            r[i][j] = false;
            c.pop_back();
            return total;
        }

        if (com.find(c) != com.end()) {
            result.push_back(c);
            com.erase(c);
            total++;
        }

        if (i - 1 >= 0 && !r[i - 1][j]) {
            total += search(board, i - 1, j);
        }

        if (i + 1 < m && !r[i + 1][j]) {
            total += search(board, i + 1, j);
        }

        if (j - 1 >= 0 && !r[i][j - 1]) {
            total += search(board, i, j - 1);
        }

        if (j + 1 < n && !r[i][j + 1]) {
            total += search(board, i, j + 1);
        }

        pre[c] -= total;
        r[i][j] = false;
        c.pop_back();
        return total;
    }
};
