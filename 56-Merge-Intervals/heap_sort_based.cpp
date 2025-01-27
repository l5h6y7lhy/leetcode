class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        l = intervals.size();

        for (int i = l / 2; i > 0; i--) {heapifyDown(intervals, i);}

        while(l > 1) {
            intervals[l - 1][0] ^= intervals[0][0];
            intervals[0][0] ^= intervals[l - 1][0];
            intervals[l - 1][0] ^= intervals[0][0];

            intervals[l - 1][1] ^= intervals[0][1];
            intervals[0][1] ^= intervals[l - 1][1];
            intervals[l - 1][1] ^= intervals[0][1];

            l--;
            heapifyDown(intervals, 1);
        }

        l = intervals.size();

        vector<int> curr;
        curr.resize(2);

        vector<vector<int>> result;

        int p_start = intervals[l - 1][0];
        int p_end   = intervals[l - 1][1];

        for (int i = l - 2; i >= 0; i--) {
            int c_start = intervals[i][0];
            int c_end   = intervals[i][1];

            if (c_start > p_end) {
                curr[0] = p_start;
                curr[1] = p_end;
                result.push_back(curr);

                p_start = c_start;
                p_end   = c_end;
                continue;
            }

            if (c_end > p_end) {p_end = c_end;}
        }

        curr[0] = p_start;
        curr[1] = p_end;
        result.push_back(curr);

        return result;
    }

private:
    int l;

    void heapifyDown(vector<vector<int>>& nums, int index) {
        int c = nums[index - 1][0];

        if (index <= (l/2)) {
            int left = nums[(2 * index) - 1][0];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = nums[2 * index][0];
            }

            if (left <= right && c > left) {
                nums[index - 1][0] ^= nums[(2 * index) - 1][0];
                nums[(2 * index) - 1][0] ^= nums[index - 1][0];
                nums[index - 1][0] ^= nums[(2 * index) - 1][0];

                nums[index - 1][1] ^= nums[(2 * index) - 1][1];
                nums[(2 * index) - 1][1] ^= nums[index - 1][1];
                nums[index - 1][1] ^= nums[(2 * index) - 1][1];

                heapifyDown(nums, 2 * index);
            }
            else if (left > right && c > right) {
                nums[index - 1][0] ^= nums[2 * index][0];
                nums[2 * index][0] ^= nums[index - 1][0];
                nums[index - 1][0] ^= nums[2 * index][0];

                nums[index - 1][1] ^= nums[2 * index][1];
                nums[2 * index][1] ^= nums[index - 1][1];
                nums[index - 1][1] ^= nums[2 * index][1];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }
};
