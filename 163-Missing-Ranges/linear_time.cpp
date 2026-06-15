class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        vector<int> curr(2);
        vector<vector<int>> result;

        if (nums.empty()) {
            curr[0] = lower;
            curr[1] = upper;
            result.push_back(curr);
            return result;
        }

        if (lower != nums[0]) {
            curr[0] = lower;
            curr[1] = nums[0] - 1;
            result.push_back(curr);
        }

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] - nums[i] > 1) {
                curr[0] = nums[i] + 1;
                curr[1] = nums[i + 1] - 1;
                result.push_back(curr);
            }
        }

        if (upper != nums.back()) {
            curr[0] = nums.back() + 1;
            curr[1] = upper;
            result.push_back(curr);
        }

        return result;
    }
};
