class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i, l = nums.size();

        for (i = 0; i < l; i++) {
            if (nums[i] <= 0 || nums[i] > l || nums[i] == i + 1) {continue;}
            if (nums[nums[i] - 1] == nums[i]) {continue;}

            int t = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = t;
            i--;
        }

        for (i = 0; i < l; i++) {
            if (nums[i] != i + 1) {
                break;
            }
        }

        return i + 1;
    }
};
