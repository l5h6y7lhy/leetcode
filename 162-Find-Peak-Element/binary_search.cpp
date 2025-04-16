class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        binarySearch(nums, 0, nums.size() - 1);
        return peak;
    }

private:
    int peak;

    void binarySearch(vector<int>& nums, int l, int r) {
        if (l == r) {
            peak = l;
            return;
        }

        int middle = (l + r) / 2;

        bool left = (middle == 0) ? true : (nums[middle] > nums[middle - 1]);
        bool right = (nums[middle] > nums[middle + 1]);

        if (left && right) {
            peak = middle;
            return;
        }

        if (!left) {
            binarySearch(nums, l, middle - 1);
        }
        else {
            binarySearch(nums, middle + 1, r);
        }

        return;
    }
};
