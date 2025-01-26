class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        l = nums.size();
        long t = (long) target;
        vector<vector<int>> result;
        if (l < 4) {return result;}

        for (int i = l / 2; i > 0; i--) {heapifyDown(nums, i);}

        while(l > 1) {
            nums[l - 1] ^= nums[0];
            nums[0] ^= nums[l - 1];
            nums[l - 1] ^= nums[0];
            l--;
            heapifyDown(nums, 1);
        }

        l = nums.size();
        if (target < 0 && nums[l-1] >= 0) {return result;}
        if (target > 0 && nums[0] <= 0) {return result;}

        vector<int> curr;

        for (int a = l - 1; a > 2; a--) {
            if (a < l - 1 && nums[a] == nums[a+1]) {continue;}
            curr.push_back(nums[a]);
            t -= nums[a];

            for (int b = a - 1; b > 1; b--) {
                if (b < a - 1 && nums[b] == nums[b+1]) {continue;}
                curr.push_back(nums[b]);
                t -= nums[b];

                int c = b - 1, d = 0;

                while (c > d) {
                    int s = nums[c] + nums[d];

                    if (s < t) {c--;}
                    else if (s > t) {d++;}
                    else {
                        curr.push_back(nums[c]);
                        curr.push_back(nums[d]);
                        result.push_back(curr);
                        curr.pop_back();
                        curr.pop_back();

                        c--; d++;
                        while(c > d && nums[c] == nums[c+1]) {c--;}
                        while(d < c && nums[d] == nums[d-1]) {d++;}
                    }
                }

                curr.pop_back();
                t += nums[b];
            }

            curr.pop_back();
            t += nums[a];
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
