class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        curr.resize(n);
        for (int i = 0; i < n; i++) {
            curr[i].assign(n, '.');
        }

        count = 0;
        search(n);
        return result;
    }

private:
    int count;
    vector<string> curr;
    vector<vector<string>> result;
    vector<int> cor;

    void search(int& n) {
        if (count == n) {
            result.push_back(curr);
            return;
        }

        for (int i = 0; i < n; i++) {
            int j;

            for (j = 0; j < count; j++) {
                int diffy = j - count;
                int diffx = cor[j] - i;

                if (!diffx || diffy == diffx || diffy == (-1) * diffx) {break;}
            }

            if (j < count) {continue;}

            curr[count][i] = 'Q';
            cor.push_back(i);
            count++;

            search(n);

            count--;
            curr[count][i] = '.';
            cor.pop_back();
        }

        return;
    }
};
