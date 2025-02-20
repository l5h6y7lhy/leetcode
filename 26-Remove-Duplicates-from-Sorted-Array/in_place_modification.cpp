class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = nums.size();
        int result = 0;

        for (int i = 0; i < l; i++) {
            if (result < 1 || nums[i] != nums[result - 1]) {
                nums[result] = nums[i];
                result++;
            }
        }

        return result;
    }
};
