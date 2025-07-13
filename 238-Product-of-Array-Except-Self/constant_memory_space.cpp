class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());

        int c = 1;

        for (int i = nums.size() - 1; i >= 0; i--) {
            c *= nums[i];
            answer[i] = c;
        }

        c = 1;

        for (int i = 0; i < nums.size(); i++) {
            c *= nums[i];
            nums[i] = c;
        }

        for (int i = 0; i < nums.size(); i++) {
            int l = (i == 0) ? 1 : nums[i - 1];
            int r = (i == nums.size() - 1) ? 1 : answer[i + 1];
            answer[i] = l * r;
        }

        return answer;
    }
};
