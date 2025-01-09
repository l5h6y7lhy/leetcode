class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        l = candidates.size();
        for (int i = l / 2; i > 0; i--) {heapifyDown(candidates, i);}

        while(l > 1) {
            candidates[l - 1] ^= candidates[0];
            candidates[0] ^= candidates[l - 1];
            candidates[l - 1] ^= candidates[0];
            l--;
            heapifyDown(candidates, 1);
        }

        csum = 0;
        t = target;
        l = candidates.size() - 1;
        search(candidates, l);

        return result;
    }

private:
    vector<int> curr;
    vector<vector<int>> result;
    int l, csum, t;

    void heapifyDown(vector<int>& nums, int index) {
        int c = nums[index - 1];

        if (index <= (l/2)) {
            int left = nums[(2 * index) - 1];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = nums[2 * index];
            }

            if (left <= right && c > left) {
                nums[index - 1] ^= nums[(2 * index) - 1];
                nums[(2 * index) - 1] ^= nums[index - 1];
                nums[index - 1] ^= nums[(2 * index) - 1];
                heapifyDown(nums, 2 * index);
            }
            else if (left > right && c > right) {
                nums[index - 1] ^= nums[2 * index];
                nums[2 * index] ^= nums[index - 1];
                nums[index - 1] ^= nums[2 * index];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }

    void search(vector<int>& candidates, int start) {
        if (csum == t) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i >= 0 && candidates[i] <= (t - csum); i--) {
            if (i < start && candidates[i] == candidates[i + 1]) {continue;}

            csum += candidates[i];
            curr.push_back(candidates[i]);
            search(candidates, i - 1);
            csum -= candidates[i];
            curr.pop_back();
        }

        return;
    }
};
