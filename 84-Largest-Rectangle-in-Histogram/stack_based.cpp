class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int l = heights.size();
        stack<int> r;
        vector<int> result(l, 0);

        for (int i = 0; i < l; i++) {
            while (!r.empty()) {
                int curr = r.top();

                if (heights[curr] < heights[i]) {
                    break;
                }

                result[curr] += heights[curr] * (i - curr - 1);
                r.pop();
            }

            int lb = r.empty() ? -1 : r.top();
            result[i] += heights[i] * (i - lb);
            r.push(i);
        }

        int rb = r.top();
        r.pop();

        while (!r.empty()) {
            int lo = r.top();
            result[lo] += heights[lo] * (rb - lo);
            r.pop();
        }
        int f = result[0];

        for (int i = 1; i < l; i++) {
            if (result[i] > f) {f = result[i];}
        }

        return f;
    }
};
