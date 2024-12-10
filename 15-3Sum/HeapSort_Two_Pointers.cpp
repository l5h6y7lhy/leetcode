class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
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
        vector<vector<int>> result;

        if (nums[reo[0]] < 0) {return result;}

        for (int i = l - 1; i >= 0; i--) {
            if (nums[reo[i]] > 0) {break;}
            if (i < l - 1 && nums[reo[i]] == nums[reo[i+1]]) {continue;}

            int j = i - 1, k = 0;
            int target = (-1) * nums[reo[i]];

            while (j > k) {
                if (nums[reo[k]] < 0) {break;}

                int c = nums[reo[j]] + nums[reo[k]];

                if (c < target) {
                    j--;
                }
                else if (c > target) {
                    k++;
                }
                else {
                    vector<int> curr;
                    curr.push_back(nums[reo[i]]);
                    curr.push_back(nums[reo[j]]);
                    curr.push_back(nums[reo[k]]);
                    result.push_back(curr);

                    j--; k++;
                    while(j > k && nums[reo[j]] == nums[reo[j+1]]) {j--;}
                    while(k < j && nums[reo[k]] == nums[reo[k-1]]) {k++;}
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
