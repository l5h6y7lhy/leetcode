class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        l = nums.size();
        long t = (long) target;
        vector<vector<int>> result;
        if (l < 4) {return result;}

        for (int i = 0; i < l; i++) {r.push_back(i);}
        for (int i = l / 2; i > 0; i--) {heapifyDown(nums, i);}

        while(l > 1) {
            r[l - 1] ^= r[0];
            r[0] ^= r[l - 1];
            r[l - 1] ^= r[0];
            l--;
            heapifyDown(nums, 1);
        }

        l = nums.size();
        if (target < 0 && nums[r[l-1]] >= 0) {return result;}
        if (target > 0 && nums[r[0]] <= 0) {return result;}

        vector<int> curr;

        for (int a = l - 1; a > 2; a--) {
            if (a < l - 1 && nums[r[a]] == nums[r[a+1]]) {continue;}
            curr.push_back(nums[r[a]]);
            t -= nums[r[a]];

            for (int b = a - 1; b > 1; b--) {
                if (b < a - 1 && nums[r[b]] == nums[r[b+1]]) {continue;}
                curr.push_back(nums[r[b]]);
                t -= nums[r[b]];

                int c = b - 1, d = 0;

                while (c > d) {
                    int s = nums[r[c]] + nums[r[d]];

                    if (s < t) {c--;}
                    else if (s > t) {d++;}
                    else {
                        curr.push_back(nums[r[c]]);
                        curr.push_back(nums[r[d]]);
                        result.push_back(curr);
                        curr.pop_back();
                        curr.pop_back();

                        c--; d++;
                        while(c > d && nums[r[c]] == nums[r[c+1]]) {c--;}
                        while(d < c && nums[r[d]] == nums[r[d-1]]) {d++;}
                    }
                }

                curr.pop_back();
                t += nums[r[b]];
            }

            curr.pop_back();
            t += nums[r[a]];
        }

        return result;
    }

private:
    int l;
    vector<int> r;

    void heapifyDown(vector<int>& nums, int index) {
        int c = nums[r[index - 1]];

        if (index <= (l/2)) {
            int left = nums[r[(2 * index) - 1]];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = nums[r[2 * index]];
            }

            if (left <= right && c > left) {
                r[index - 1] ^= r[(2 * index) - 1];
                r[(2 * index) - 1] ^= r[index - 1];
                r[index - 1] ^= r[(2 * index) - 1];
                heapifyDown(nums, 2 * index);
            }
            else if (left > right && c > right) {
                r[index - 1] ^= r[2 * index];
                r[2 * index] ^= r[index - 1];
                r[index - 1] ^= r[2 * index];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }
};
