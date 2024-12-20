class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result = 0;
        int l = nums.size();

        for (int i = 0; i < l; i++) {
            if (nums[i] != val) {
                nums[result] = nums[i];
                result++;
            }
        }

        return result;
    }
};
