class Solution {
public:
    int jump(vector<int>& nums) {
        int l = nums.size();
        int result = 0;
        int prev = 0;
        int last = 0;

        while (last < l - 1) {
            int dist = 0;

            for (int i = prev; i <= last; i++) {
                if (i + nums[i] > dist) {
                    dist = i + nums[i];
                }
            }

            prev = last + 1;
            last = dist;
            result++;
        }

        return result;
    }
};
