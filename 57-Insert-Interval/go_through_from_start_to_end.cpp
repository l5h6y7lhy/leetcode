class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i, l = intervals.size();
        vector<vector<int>> result;

        for (i = 0; i < l; i++) {
            if (newInterval[1] < intervals[i][0]) {
                break;
            }

            if (newInterval[0] > intervals[i][1]) {
                result.push_back(intervals[i]);
                continue;
            }

            if (intervals[i][0] < newInterval[0]) {
                newInterval[0] = intervals[i][0];
            }

            if (intervals[i][1] > newInterval[1]) {
                newInterval[1] = intervals[i][1];
            }
        }

        result.push_back(newInterval);

        while (i < l) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};
