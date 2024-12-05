class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        l = nums.size();

        for (int i = 0; i < l; i++) {result.push_back(i);}
        for (int i = l / 2; i > 0; i--) {heapifyDown(nums, i);}

        while(l > 1) {
            result[l - 1] ^= result[0];
            result[0] ^= result[l - 1];
            result[l - 1] ^= result[0];
            l--;
            heapifyDown(nums, 1);
        }

        int i = 0, j = nums.size() - 1;
        vector<int> index;

        while (i < j) {
            int c_sum = nums[result[i]] + nums[result[j]];
            if (c_sum < target) {j--;}
            else if (c_sum > target) {i++;}
            else {
                index.push_back(result[i]);
                index.push_back(result[j]);
                break;
            }
        }

        return index;
    }

private:
    int l;
    vector<int> result;

    void heapifyDown(vector<int>& nums, int index) {
        int c = nums[result[index - 1]];

        if (index <= (l/2)) {
            int left = nums[result[(2 * index) - 1]];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = nums[result[2 * index]];
            }

            if (left <= right && c > left) {
                result[index - 1] ^= result[(2 * index) - 1];
                result[(2 * index) - 1] ^= result[index - 1];
                result[index - 1] ^= result[(2 * index) - 1];
                heapifyDown(nums, 2 * index);
            }
            else if (left > right && c > right) {
                result[index - 1] ^= result[2 * index];
                result[2 * index] ^= result[index - 1];
                result[index - 1] ^= result[2 * index];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }
};
