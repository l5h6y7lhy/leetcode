class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        l = nums.size();

        for (int i = l / 2; i > 0; i--) {heapifyDown(nums, i);}

        while(l > 1) {
            nums[l - 1] ^= nums[0];
            nums[0] ^= nums[l - 1];
            nums[l - 1] ^= nums[0];
            l--;
            heapifyDown(nums, 1);
        }

        l = nums.size() - 1;
        result.push_back(curr);

        search(nums, l);
        return result;
    }

private:
    int l;
    vector<int> curr;
    vector<vector<int>> result;

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

    void search(vector<int>& nums, int s) {
        for (int i = s; i >= 0; i--) {
            if (i < s && nums[i] == nums[i + 1]) {continue;}
            curr.push_back(nums[i]);
            result.push_back(curr);
            search(nums, i - 1);
            curr.pop_back();
        }

        return;
    }
};
