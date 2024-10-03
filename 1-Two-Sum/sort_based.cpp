class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = mergeSort_index(nums, 0, nums.size());
        int i = 0, j = nums.size() - 1;
        vector<int> index;

        while (i < j) {
            if (result[i] + result[j] < target) {i++;}
            else if (result[i] + result[j] > target) {j--;}
            else {
                index.push_back(result[i+nums.size()]);
                index.push_back(result[j+nums.size()]);
                break;
            }
        }

        if (index[0] > index[1]) {
            index[0] ^= index[1];
            index[1] ^= index[0];
            index[0] ^= index[1];
        }

        return index;
    }

private:
    vector<int> mergeSort_index(vector<int>& nums, int start, int end) {
        int len = end - start, l;
        vector<int> result;
        result.resize(2 * len);

        if(end - start == 1) {
            result[0] = nums[start];
            result[1] = start;
            return result;
        }

        if (len % 2 == 0) {l = len / 2;}
        else {l = (len/2)+1;}
        int r = len - l;

        vector<int> left = mergeSort_index(nums, start, start + l);
        vector<int> right = mergeSort_index(nums, start + l, end);

        int lp=0, rp=0;

        while(lp < l && rp < r){
            if (left[lp] <= right[rp]){
                result[lp+rp] = left[lp];
                result[lp + rp + len] = left[lp + l];
                lp++;
            }
            else {
                result[lp+rp] = right[rp];
                result[lp + rp + len] = right[rp + r];
                rp++;
            }
        }

        while (lp < l) {
            result[lp+rp] = left[lp];
            result[lp + rp + len] = left[lp + l];
            lp++;
        }

        while (rp < r) {
            result[lp+rp] = right[rp];
            result[lp + rp + len] = right[rp + r];
            rp++;
        }

        return result;
    }
};
