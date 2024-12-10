class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        l = nums.size();

        for (int i = 0; i < l; i++) {reo.push_back(i);}
        for (int i = l / 2; i > 0; i--) {heapifyDown(nums, i);}

        while(l > 1) {
            reo[l - 1] ^= reo[0];
            reo[0] ^= reo[l - 1];
            reo[l - 1] ^= reo[0];
            l--;
            heapifyDown(nums, 1);
        }

        l = nums.size();
        int result, diff = INT_MAX;

        for (int i = l - 1; i >= 0; i--) {
            int j = i - 1, k = 0;

            while (j > k) {
                int sum = nums[reo[i]] + nums[reo[j]] + nums[reo[k]];
                int tmp = target - sum;

                if (!tmp) {return target;}

                if (tmp < 0) {
                    do {
                        k++;
                    } while (j > k && nums[reo[k]] == nums[reo[k - 1]]);
                    tmp *= (-1);
                }
                else {
                    do {
                        j--;
                    } while (j > k && nums[reo[j]] == nums[reo[j + 1]]);
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
    vector<int> reo;

    void heapifyDown(vector<int>& nums, int index) {
        int c = nums[reo[index - 1]];

        if (index <= (l/2)) {
            int left = nums[reo[(2 * index) - 1]];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = nums[reo[2 * index]];
            }

            if (left <= right && c > left) {
                reo[index - 1] ^= reo[(2 * index) - 1];
                reo[(2 * index) - 1] ^= reo[index - 1];
                reo[index - 1] ^= reo[(2 * index) - 1];
                heapifyDown(nums, 2 * index);
            }
            else if (left > right && c > right) {
                reo[index - 1] ^= reo[2 * index];
                reo[2 * index] ^= reo[index - 1];
                reo[index - 1] ^= reo[2 * index];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }
};
