class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        int c;
        vector<int> tmp(1);
        vector<vector<int>> r1, r2;

        for (int i = 1; i <= n; i++) {
            tmp[0] = i;
            r1.push_back(tmp);
        }

        for (c = 2; c <= k; c++) {
            vector<vector<int>>& prev = (c % 2) ? r2 : r1;
            vector<vector<int>>& curr = (c % 2) ? r1 : r2;

            curr.clear();

            for (int i = 0; i < prev.size(); i++) {
                tmp = prev[i];
                tmp.push_back(0);

                for (int j = tmp[c - 2] + 1; j <= n; j++) {
                    tmp[c - 1] = j;
                    curr.push_back(tmp);
                }
            }
        }

        return (c % 2) ? r2 : r1;
    }
};