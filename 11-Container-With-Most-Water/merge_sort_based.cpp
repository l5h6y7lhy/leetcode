class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        vector<int> result = mergeSort_index(height, 0, l);

        int left = result[l-2];
        int right = result[l-1];
        if (left > right) {
            left ^= right;
            right ^= left;
            left ^= right;
        }

        int water = calcW(height, left, right);

        for(int i = l-3; i >= 0; i--) {
            if (left == 0 && right == l-1) {break;}
            if(result[i] > left && result[i] < right) {continue;}

            int tmp;
            if (result[i] > right) {
                tmp = calcW(height, left, (right = result[i]));
            }
            else {
                tmp = calcW(height, (left = result[i]), right);
            }
            if (tmp > water) {water = tmp;}
        }

        return water;
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

    int calcW(vector<int>& nums, int& left, int& right) {
        return (right - left) * std::min(nums[left], nums[right]);
    }
};
