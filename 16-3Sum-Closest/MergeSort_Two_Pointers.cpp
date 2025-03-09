class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int l = nums.size();
        tmp.resize(l);

        mergeSort(nums, 0, l);
        int result, diff = INT_MAX;

        for (int i = 0; i < l; i++) {
            if (i > 0 && nums[i] == nums[i-1]) {continue;}

            int j = i+1, k = l-1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                int tmp = target - sum;

                if (!tmp) {return target;}

                if (tmp < 0) {
                    do {
                        k--;
                    } while (j < k && nums[k] == nums[k+1]);
                    tmp *= (-1);
                }
                else {
                    do {
                        j++;
                    } while (j < k && nums[j] == nums[j-1]);
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
    vector<int> tmp;

    void mergeSort(vector<int>& nums, int start, int end) {
        int len = end - start, l;

        if(len == 1) {
            return;
        }

        if (len % 2 == 0) {l = len / 2;}
        else {l = (len/2)+1;}
        int r = len - l;

        mergeSort(nums, start, start + l);
        mergeSort(nums, start + l, end);

        int lp=0, rp=0;

        while(lp < l && rp < r){
            if (nums[start + lp] <= nums[start + l + rp]){
                tmp[start+ lp + rp] = nums[start + lp];
                lp++;
            }
            else {
                tmp[start+ lp + rp] = nums[start + l + rp];
                rp++;
            }
        }

        while (lp < l) {
            tmp[start+ lp + rp] = nums[start + lp];
            lp++;
        }

        while (rp < r) {
            tmp[start+ lp + rp] = nums[start + l + rp];
            rp++;
        }

        for (int i = start; i < end; i++) {nums[i] = tmp[i];}

        return;
    }
};
