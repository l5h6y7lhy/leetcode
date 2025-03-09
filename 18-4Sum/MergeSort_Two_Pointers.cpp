class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int l = nums.size();
        tmp.resize(l);

        long t = (long) target;
        vector<vector<int>> result;
        if (l < 4) {return result;}

        mergeSort(nums, 0, l);
        if (target < 0 && nums[0] >= 0) {return result;}
        if (target > 0 && nums[l-1] <= 0) {return result;}

        vector<int> curr;

        for (int a = 0; a < l - 3; a++) {
            if (a > 0 && nums[a] == nums[a-1]) {continue;}
            curr.push_back(nums[a]);
            t -= nums[a];

            for (int b = a + 1; b < l - 2; b++) {
                if (b > a + 1 && nums[b] == nums[b-1]) {continue;}
                curr.push_back(nums[b]);
                t -= nums[b];

                int c = b + 1, d = l - 1;

                while (c < d) {
                    int s = nums[c] + nums[d];

                    if (s < t) {c++;}
                    else if (s > t) {d--;}
                    else {
                        curr.push_back(nums[c]);
                        curr.push_back(nums[d]);
                        result.push_back(curr);
                        curr.pop_back();
                        curr.pop_back();

                        c++; d--;
                        while(c < d && nums[c] == nums[c-1]) {c++;}
                        while(d > c && nums[d] == nums[d+1]) {d--;}
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
