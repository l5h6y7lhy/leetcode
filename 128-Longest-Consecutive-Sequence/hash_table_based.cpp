class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0;
        unordered_map<int, int> r;

        for (int i = 0; i < nums.size(); i++) {
            if (r.find(nums[i]) != r.end()) {continue;}

            r[nums[i]] = 0;
            int left = nums[i], right = nums[i];

            if (r.find(nums[i] - 1) != r.end()) {
                left = nums[i] - 1 + r[nums[i] - 1];
            }

            if (r.find(nums[i] + 1) != r.end()) {
                right = nums[i] + 1 + r[nums[i] + 1];
            }

            r[left] = right - left;
            r[right] = left - right;

            if (right - left + 1 > result) {result = right - left + 1;}
        }

        return result;
    }
};
