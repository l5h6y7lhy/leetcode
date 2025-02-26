class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev, curr;
        prev.push_back(1);

        for (int i = 0; i < rowIndex; i++) {
            curr.resize(i + 2);

            for (int j = 0; j < i + 2; j++) {
                int t1 = (j - 1 < 0) ? 0 : prev[j - 1];
                int t2 = (j == i + 1) ? 0 : prev[j];
                curr[j] = t1 + t2;
            }

            prev = curr;
        }

        return prev;
    }
};
