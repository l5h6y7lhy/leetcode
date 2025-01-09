class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> r;
        int result = 0;

        for (int i = 0; i < height.size(); i++) {
            int last;

            while (!r.empty() && height[i] >= (last = height[r.top()])) {
                r.pop();
                if (r.empty()) {break;}

                int c = (height[i] > height[r.top()]) ? height[r.top()] : height[i];
                result += (i - r.top() - 1) * (c - last);
            }

            r.push(i);
        }

        return result;
    }
};
