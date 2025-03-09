class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int l = nums.size();
        tmp.resize(l);

        half = l / 2;
        ul = l - 1;

        if (l % 2 == 0) {half--;}
        if (l % 2 == 1) {ul--;}

        mergeSort(nums, 0, l);

        return;
    }

private:
    int half;
    int ul;
    vector<int> tmp;

    int coordinate(int i) {
        if (i <= half) {return (half - i) * 2;}
        return ul - (2 * (i - half - 1));
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        int len = end - start, l;

        if(len == 1) {
            return;
        }

        if (len % 2 == 0) {l = len / 2;}
        else {l = (len / 2) + 1;}
        int r = len - l;

        mergeSort(nums, start,     start + l);
        mergeSort(nums, start + l, end);

        int lp = 0, rp = 0;

        while (lp < l && rp < r){
            if (nums[coordinate(start + lp)] <= nums[coordinate(start + l + rp)]){
                tmp[start + lp + rp] = nums[coordinate(start + lp)];
                lp++;
            }
            else {
                tmp[start + lp + rp] = nums[coordinate(start + l + rp)];
                rp++;
            }
        }

        while (lp < l) {
            tmp[start + lp + rp] = nums[coordinate(start + lp)];
            lp++;
        }

        while (rp < r) {
            tmp[start + lp + rp] = nums[coordinate(start + l + rp)];
            rp++;
        }

        for (int i = start; i < end; i++) {nums[coordinate(i)] = tmp[i];}

        return;
    }
};
