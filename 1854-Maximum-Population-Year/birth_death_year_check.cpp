class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int maxBY = 1950;
        vector<int> r(101, 0);

        for (int i = 0; i < logs.size(); i++) {
            if (logs[i][0] > maxBY) {maxBY = logs[i][0];}
            r[logs[i][0] - 1950]++;
            r[logs[i][1] - 1950]--;
        }

        int p = 0, maxP = 0;
        int year;

        for (int i = 1950; i <= maxBY; i++) {
            p += r[i - 1950];

            if (p > maxP) {
                maxP = p;
                year = i;
            }
        }

        return year;
    }
};
