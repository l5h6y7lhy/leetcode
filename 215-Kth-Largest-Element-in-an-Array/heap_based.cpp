class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for (int i = k / 2; i > 0; i--) {heapifyDown(nums, i, k);}

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] <= nums[0]) {continue;}
            nums[0] = nums[i];
            heapifyDown(nums, 1, k);
        }

        return nums[0];
    }

private:
    void heapifyDown(vector<int>& nums,int index, int& k) {
        int c = nums[index - 1];

        if (index <= (k/2)) {
            int left = nums[(2 * index) - 1];
            int right = INT_MAX;

            if ((2 * index) + 1 <= k) {
                right = nums[2 * index];
            }

            if (left <= right && c > left) {
                nums[index - 1] ^= nums[(2 * index) - 1];
                nums[(2 * index) - 1] ^= nums[index - 1];
                nums[index - 1] ^= nums[(2 * index) - 1];
                heapifyDown(nums, 2 * index, k);
            }
            else if (left > right && c > right) {
                nums[index - 1] ^= nums[2 * index];
                nums[2 * index] ^= nums[index - 1];
                nums[index - 1] ^= nums[2 * index];
                heapifyDown(nums, (2 * index) + 1, k);
            }
        }

        return;
    }
};
