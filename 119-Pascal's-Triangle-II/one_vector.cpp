class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> r;
        r.assign(rowIndex + 1, 0);
        r[0] = 1;

        for (int i = 0; i < rowIndex; i++) {
            int prev = r[0] + r[1];
            for (int j = 2; j < i + 2; j++) {
                int tmp = r[j - 1] + r[j];
                r[j - 1] = prev;
                prev = tmp;
            }

            r[i + 1] = prev;
        }

        return r;
    }
};
