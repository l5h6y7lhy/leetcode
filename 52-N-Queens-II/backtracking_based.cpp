class Solution {
public:
    int totalNQueens(int n) {
        count = 0;
        result = 0;
        search(n);
        return result;
    }

private:
    int count, result;
    vector<int> cor;

    void search(int& n) {
        if (count == n) {
            result++;
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

            cor.push_back(i);
            count++;

            search(n);

            count--;
            cor.pop_back();
        }

        return;
    }
};
