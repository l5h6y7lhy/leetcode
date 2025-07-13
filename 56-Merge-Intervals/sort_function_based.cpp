class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int l = intervals.size();
        sort(intervals.begin(), intervals.end());

        vector<int> curr;
        curr.resize(2);

        vector<vector<int>> result;

        int p_start = intervals[0][0];
        int p_end   = intervals[0][1];

        for (int i = 1; i < l; i++) {
            int c_start = intervals[i][0];
            int c_end   = intervals[i][1];

            if (c_start > p_end) {
                curr[0] = p_start;
                curr[1] = p_end;
                result.push_back(curr);

                p_start = c_start;
                p_end   = c_end;
                continue;
            }

            if (c_end > p_end) {p_end = c_end;}
        }

        curr[0] = p_start;
        curr[1] = p_end;
        result.push_back(curr);

        return result;
    }
};
