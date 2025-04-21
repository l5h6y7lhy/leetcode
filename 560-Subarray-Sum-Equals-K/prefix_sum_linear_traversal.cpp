class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> r;
        r[0] = 1;
        int sum = 0, total = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            total += r[sum - k];
            r[sum]++;
        }

        return total;
    }
};
