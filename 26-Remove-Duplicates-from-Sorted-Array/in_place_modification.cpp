class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = -200;
        int l = nums.size();
        int result = 0;

        for (int i = 0; i < l; i++) {
            if (nums[i] != prev) {
                prev = nums[i];
                nums[result] = nums[i];
                result++;
            }
        }

        return result;
    }
};
