class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int l = nums.size();
        vector<int> reo = mergeSort_index(nums, 0, l);
        int result, diff = INT_MAX;

        for (int i = 0; i < l; i++) {
            int j = i+1, k = l-1;

            while (j < k) {
                int sum = nums[reo[i]] + nums[reo[j]] + nums[reo[k]];
                int tmp = target - sum;

                if (!tmp) {return target;}

                if (tmp < 0) {
                    do {
                        k--;
                    } while (j < k && nums[reo[k]] == nums[reo[k+1]]);
                    tmp *= (-1);
                }
                else {
                    do {
                        j++;
                    } while (j < k && nums[reo[j]] == nums[reo[j-1]]);
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
