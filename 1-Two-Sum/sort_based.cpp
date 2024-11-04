class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = mergeSort_index(nums, 0, nums.size());
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
