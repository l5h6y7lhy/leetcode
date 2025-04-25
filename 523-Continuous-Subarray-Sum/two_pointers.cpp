class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2) {return false;}

        int sum = nums[0] + nums[1];
        if (sum % k == 0) {return true;}

        int prev = 0;
        unordered_set<int> r;
        r.insert(0);

        for (int i = 0; i < nums.size() - 2; i++) {
            prev += nums[i];
            r.insert(prev % k);
            sum += nums[i + 2];

            int tmp = sum % k;
            if (r.find(tmp) != r.end()) {return true;}
        }

        return false;
    }
};
