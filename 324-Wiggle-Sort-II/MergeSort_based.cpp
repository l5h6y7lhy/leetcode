class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if ((l = nums.size()) == 1) {return;}

        half = l / 2;
        ul = l - 1;

        if (l % 2 == 0) {half--;}
        if (l % 2 == 1) {ul--;}

        vector<int> reo = mergeSort(nums, 0, l);

        for (int i = 0; i < l; i++) {
            nums[coordinate(i)] = reo[i];
        }

        return;
    }

private:
    int l;
    int half;
    int ul;

    int coordinate(int& i) {
        if (i <= half) {return (half - i) * 2;}
        return ul - (2 * (i - half - 1));
    }

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
