class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        for (int i = 0; i < l; i++) {result.push_back(i);}
        tmp.resize(l);

        mergeSort_index(height, 0, l);

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

    int calcW(vector<int>& nums, int& left, int& right) {
        return (right - left) * std::min(nums[left], nums[right]);
    }
};
