class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> r(100, 0);

        for (int i = 0; i < logs.size(); i++) {
            for (int j = 0; j < logs[i][1] - logs[i][0]; j++) {
                r[logs[i][0] + j - 1950]++;
            }
        }

        int year = 1950;
        int maxp = r[0];

        for (int i = 1; i < 100; i++) {
            if (r[i] > maxp) {
                year = 1950 + i;
                maxp = r[i];
            }
        }

        return year;
    }
};
