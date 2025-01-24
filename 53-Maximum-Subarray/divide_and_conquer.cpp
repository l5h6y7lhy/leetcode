class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        m = INT_MIN;
        divide(nums, 0, nums.size() - 1);
        return m;
    }

private:
    int m;

    vector<int> divide(vector<int>& nums, int start, int end) {
        vector<int> result;
        result.resize(3);

        if (start == end) {
            if ((result[2] = nums[start]) > m) {m = result[2];}
            result[0] = nums[start];
            result[1] = nums[start];
            return result;
        }

        int half = (end - start + 1) / 2;
        vector<int> r1 = divide(nums, start, start + half - 1);
        vector<int> r2 = divide(nums, start + half, end);

        if (r1[1] + r2[0] > m) {
            m = r1[1] + r2[0];
        }

        result[2] = r1[2] + r2[2];

        result[0] = (r1[2] + r2[0] > r1[0]) ? r1[2] + r2[0] : r1[0];
        result[1] = (r2[2] + r1[1] > r2[1]) ? r2[2] + r1[1] : r2[1];

        return result;
    }
};
