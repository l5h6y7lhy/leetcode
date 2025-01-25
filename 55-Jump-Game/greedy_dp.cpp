class Solution {
public:
    bool canJump(vector<int>& nums) {
        int l = nums.size();
        int prev = 0;
        int last = 0;

        while (last < l - 1) {
            int dist = 0;

            for (int i = prev; i <= last; i++) {
                if (i + nums[i] > dist) {
                    dist = i + nums[i];
                }
            }

            if (dist <= last) {return false;}

            prev = last + 1;
            last = dist;
        }

        return true;
    }
};
