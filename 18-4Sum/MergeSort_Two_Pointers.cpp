class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int l = nums.size();
        long t = (long) target;
        vector<vector<int>> result;
        if (l < 4) {return result;}

        vector<int> r = mergeSort(nums, 0, l);
        if (target < 0 && r[0] >= 0) {return result;}
        if (target > 0 && r[l-1] <= 0) {return result;}

        vector<int> curr;

        for (int a = 0; a < l - 3; a++) {
            if (a > 0 && r[a] == r[a-1]) {continue;}
            curr.push_back(r[a]);
            t -= r[a];

            for (int b = a + 1; b < l - 2; b++) {
                if (b > a + 1 && r[b] == r[b-1]) {continue;}
                curr.push_back(r[b]);
                t -= r[b];

                int c = b + 1, d = l - 1;

                while (c < d) {
                    int s = r[c] + r[d];

                    if (s < t) {c++;}
                    else if (s > t) {d--;}
                    else {
                        curr.push_back(r[c]);
                        curr.push_back(r[d]);
                        result.push_back(curr);
                        curr.pop_back();
                        curr.pop_back();

                        c++; d--;
                        while(c < d && r[c] == r[c-1]) {c++;}
                        while(d > c && r[d] == r[d+1]) {d--;}
                    }
                }

                curr.pop_back();
                t += r[b];
            }

            curr.pop_back();
            t += r[a];
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
