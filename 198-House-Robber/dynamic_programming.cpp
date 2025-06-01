class Solution {
public:
    int rob(vector<int>& nums) {
        nums.push_back(0);

        for (int i = nums.size() - 3; i >= 0; i--) {
            nums[i] = max(nums[i] + nums[i + 2], nums[i + 1]);
        }

        return nums[0];
    }
};
