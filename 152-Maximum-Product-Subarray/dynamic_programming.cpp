class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int c_min = nums[0];
        int c_max = nums[0];
        int result = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            result = max(result, nums[i]);

            int tmp = c_max;
            c_max = max(nums[i] * c_min, nums[i] * c_max);

            result = max(result, c_max);

            c_min = min(nums[i] * c_min, nums[i] * tmp);
            c_min = min(c_min, nums[i]);
            c_max = max(c_max, nums[i]);
        }

        return result;
    }
};
