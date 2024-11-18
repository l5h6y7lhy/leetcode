class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int l = nums.size();
        long t = (long) target;
        vector<vector<int>> result;
        if (l < 4) {return result;}

        vector<int> r = mergeSort_index(nums, 0, l);
        if (target < 0 && nums[r[0]] >= 0) {return result;}
        if (target > 0 && nums[r[l-1]] <= 0) {return result;}

        vector<int> curr;

        for (int a = 0; a < l - 3; a++) {
            if (a > 0 && nums[r[a]] == nums[r[a-1]]) {continue;}
            curr.push_back(nums[r[a]]);
            t -= nums[r[a]];

            for (int b = a + 1; b < l - 2; b++) {
                if (b > a + 1 && nums[r[b]] == nums[r[b-1]]) {continue;}
                curr.push_back(nums[r[b]]);
                t -= nums[r[b]];

                int c = b + 1, d = l - 1;

                while (c < d) {
                    int s = nums[r[c]] + nums[r[d]];

                    if (s < t) {c++;}
                    else if (s > t) {d--;}
                    else {
                        curr.push_back(nums[r[c]]);
                        curr.push_back(nums[r[d]]);
                        result.push_back(curr);
                        curr.pop_back();
                        curr.pop_back();

                        c++; d--;
                        while(c < d && nums[r[c]] == nums[r[c-1]]) {c++;}
                        while(d > c && nums[r[d]] == nums[r[d+1]]) {d--;}
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
    vector<int> mergeSort_index(vector<int>& nums, int start, int end) {
        int len = end - start, l;
        vector<int> result;
        result.resize(len);

        if(len == 1) {
            result[0] = start;
            return result;
        }

        if (len % 2 == 0) {l = len / 2;}
        else {l = (len/2)+1;}
        int r = len - l;

        vector<int> left = mergeSort_index(nums, start, start + l);
        vector<int> right = mergeSort_index(nums, start + l, end);

        int lp=0, rp=0;

        while(lp < l && rp < r){
            if (nums[left[lp]] <= nums[right[rp]]){
                result[lp+rp] = left[lp];
                lp++;
            }
            else {
                result[lp+rp] = right[rp];
                rp++;
            }
        }

        while (lp < l) {
            result[lp+rp] = left[lp];
            lp++;
        }

        while (rp < r) {
            result[lp+rp] = right[rp];
            rp++;
        }

        return result;
    }
};
