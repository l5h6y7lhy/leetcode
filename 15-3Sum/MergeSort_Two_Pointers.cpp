class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int l = nums.size();
        vector<int> reo = mergeSort(nums, 0, l);

        vector<vector<int>> result;
        if (reo[l-1] < 0) {return result;}

        for (int i = 0; i < l; i++) {
            if (reo[i] > 0) {break;}
            if (i > 0 && reo[i] == reo[i-1]) {continue;}

            int j = i+1, k = l-1;
            int target = (-1) * reo[i];

            while (j < k) {
                if (reo[k] < 0) {break;}

                int c = reo[j] + reo[k];

                if (c < target) {j++;}
                else if ( c > target) {k--;}
                else {
                    vector<int> curr;
                    curr.push_back(reo[i]);
                    curr.push_back(reo[j]);
                    curr.push_back(reo[k]);
                    result.push_back(curr);

                    j++; k--;
                    while(j < k && reo[j] == reo[j-1]) {j++;}
                    while(k > j && reo[k] == reo[k+1]) {k--;}
                }
            }
        }

        return result;
    }

private:
    vector<int> mergeSort(vector<int>& nums, int start, int end) {
        int len = end - start, l;
        vector<int> result;
        result.resize(len);

        if(len == 1) {
            result[0] = nums[start];
            return result;
        }

        if (len % 2 == 0) {l = len / 2;}
        else {l = (len/2)+1;}
        int r = len - l;

        vector<int> left = mergeSort(nums, start, start + l);
        vector<int> right = mergeSort(nums, start + l, end);

        int lp=0, rp=0;

        while(lp < l && rp < r){
            if (left[lp] <= right[rp]){
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
