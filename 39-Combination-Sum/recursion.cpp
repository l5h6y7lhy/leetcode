class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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

        for (l = candidates.size() - 1; l >= 0 && candidates[l] <= (t - csum); l--) {
            csum += candidates[l];
            curr.push_back(candidates[l]);
            search(candidates, l);
            csum -= candidates[l];
            curr.pop_back();
        }

        return result;
    }

private:
    vector<int> curr;
    vector<vector<int>> result;
    int l, csum, t;

    void search(vector<int>& candidates, int& start) {
        if (csum == t) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i >= 0 && candidates[i] <= (t - csum); i--) {
            csum += candidates[i];
            curr.push_back(candidates[i]);
            search(candidates, i);
            csum -= candidates[i];
            curr.pop_back();
        }

        return;
    }

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
};