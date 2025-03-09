class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l = nums.size();
        tmp.resize(l);

        mergeSort(nums, 0, l);

        vector<vector<int>> result;
        if (nums[l-1] < 0) {return result;}

        for (int i = 0; i < l; i++) {
            if (nums[i] > 0) {break;}
            if (i > 0 && nums[i] == nums[i-1]) {continue;}

            int j = i+1, k = l-1;
            int target = (-1) * nums[i];

            while (j < k) {
                if (nums[k] < 0) {break;}

                int c = nums[j] + nums[k];

                if (c < target) {j++;}
                else if ( c > target) {k--;}
                else {
                    vector<int> curr;
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);
                    result.push_back(curr);

                    j++; k--;
                    while(j < k && nums[j] == nums[j-1]) {j++;}
                    while(k > j && nums[k] == nums[k+1]) {k--;}
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
