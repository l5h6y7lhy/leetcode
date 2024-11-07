class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int result = 0;

        while(l < r) {
            int water = (r - l) * std::min(height[l], height[r]);
            if (water > result) {result = water;}

            if (height[l] <= height[r]) {l++;}
            else {r--;}
        }

        return result;
    }
};
