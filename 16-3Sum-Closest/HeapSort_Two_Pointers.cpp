class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        l = nums.size();

        for (int i = l / 2; i > 0; i--) {heapifyDown(nums, i);}

        while(l > 1) {
            nums[l - 1] ^= nums[0];
            nums[0] ^= nums[l - 1];
            nums[l - 1] ^= nums[0];
            l--;
            heapifyDown(nums, 1);
        }

        l = nums.size();
        int result, diff = INT_MAX;

        for (int i = l - 1; i >= 0; i--) {
            int j = i - 1, k = 0;

            while (j > k) {
                int sum = nums[i] + nums[j] + nums[k];
                int tmp = target - sum;

                if (!tmp) {return target;}

                if (tmp < 0) {
                    do {
                        k++;
                    } while (j > k && nums[k] == nums[k - 1]);
                    tmp *= (-1);
                }
                else {
                    do {
                        j--;
                    } while (j > k && nums[j] == nums[j + 1]);
                }

                if (tmp < diff) {
                    diff = tmp;
                    result = sum;
                }
            }
        }

        return result;
    }

private:
    int l;

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
