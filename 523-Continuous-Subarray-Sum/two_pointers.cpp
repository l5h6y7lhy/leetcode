class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {return false;}

        int sum = nums[0] + nums[1];
        if (sum % k == 0) {return true;}

        int prev = 0;
        unordered_map<int, bool> r;

        for (int i = 0; i < nums.size() - 2; i++) {
            prev += nums[i];
            r[prev % k] = true;
            sum += nums[i + 2];
            int tmp = sum % k;

            if (tmp == 0) {return true;}
            if (r[tmp]) {return true;}
        }

        return false;
    }
};
