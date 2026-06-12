class Solution {
public:
    int maxProduct(vector<int>& nums) {
        m = INT_MIN;
        divide(nums, 0, nums.size() - 1);
        return m;
    }

private:
    int m;

    vector<int> divide(vector<int>& nums, int start, int end) {
        vector<int> result;
        result.resize(5);

        if (start == end) {
            if ((result[4] = nums[start]) > m) {m = result[4];}
            result[0] = nums[start];
            result[1] = nums[start];
            result[2] = nums[start];
            result[3] = nums[start];
            return result;
        }

        int half = (end - start + 1) / 2;
        vector<int> r1 = divide(nums, start, start + half - 1);
        vector<int> r2 = divide(nums, start + half, end);

        if (r1[3] * r2[1] > m) {
            m = r1[3] * r2[1];
        }

        if (r1[2] * r2[0] > m) {
            m = r1[2] * r2[0];
        }

        result[4] = r1[4] * r2[4];

        int extreme1 = r1[4] * r2[0];
        int extreme2 = r1[4] * r2[1];
        result[0] = min(r1[0], min(extreme1, extreme2));
        result[1] = max(r1[1], max(extreme1, extreme2));

        extreme1 = r1[2] * r2[4];
        extreme2 = r1[3] * r2[4];
        result[2] = min(r2[2], min(extreme1, extreme2));
        result[3] = max(r2[3], max(extreme1, extreme2));

        return result;
    }
};
