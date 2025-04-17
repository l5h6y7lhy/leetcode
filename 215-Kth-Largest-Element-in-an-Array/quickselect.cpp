class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        tmp.resize(nums.size());
        return QuickSelect(nums, k, 0, nums.size() - 1);
    }

private:
    vector<int> tmp;

    int QuickSelect(vector<int>& nums, int k, int start, int end) {
        int c_count = 1;
        int lc = 0, rc = 0;

        for (int i = start + 1; i <= end; i++) {
            if (nums[i] < nums[start]) {
                tmp[start + lc] = nums[i];
                lc++;
            }
            else if (nums[i] > nums[start]) {
                tmp[end - rc] = nums[i];
                rc++;
            }
            else {c_count++;}
        }

        if (rc >= k) {
            for (int i = 0; i < rc; i++) {nums[end - i] = tmp[end - i];}
            return QuickSelect(nums, k, end - rc + 1, end);
        }
        else if (rc + c_count >= k) {return nums[start];}

        for (int i = 0; i < lc; i++) {nums[start + i] = tmp[start + i];}
        return QuickSelect(nums, k - rc - c_count, start, start + lc - 1);
    }
};
