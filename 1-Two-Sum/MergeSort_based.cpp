class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {result.push_back(i);}
        tmp.resize(nums.size());

        mergeSort_index(nums, 0, nums.size());
        int i = 0, j = nums.size() - 1;
        vector<int> index;

        while (i < j) {
            int c_sum = nums[result[i]] + nums[result[j]];
            if (c_sum < target) {i++;}
            else if (c_sum > target) {j--;}
            else {
                index.push_back(result[i]);
                index.push_back(result[j]);
                break;
            }
        }

        return index;
    }

private:
    vector<int> result, tmp;

    void mergeSort_index(vector<int>& nums, int start, int end) {
        int len = end - start, l;

        if(len == 1) {
            return;
        }

        if (len % 2 == 0) {l = len / 2;}
        else {l = (len/2)+1;}
        int r = len - l;

        mergeSort_index(nums, start, start + l);
        mergeSort_index(nums, start + l, end);

        int lp=0, rp=0;

        while(lp < l && rp < r){
            if (nums[result[start + lp]] <= nums[result[start + l + rp]]){
                tmp[start+ lp + rp] = result[start + lp];
                lp++;
            }
            else {
                tmp[start+ lp + rp] = result[start + l + rp];
                rp++;
            }
        }

        while (lp < l) {
            tmp[start+ lp + rp] = result[start + lp];
            lp++;
        }

        while (rp < r) {
            tmp[start+ lp + rp] = result[start + l + rp];
            rp++;
        }

        for (int i = start; i < end; i++) {result[i] = tmp[i];}

        return;
    }
};
