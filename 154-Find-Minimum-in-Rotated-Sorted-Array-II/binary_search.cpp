class Solution {
public:
    int findMin(vector<int>& nums) {
        l = nums.size();
        int start = 0;
        int end = l - 1;

        offset = findOffset(nums, start, end);
        return nums[offset];
    }

private:
    int offset;
    int l;

    int findOffset(vector<int>& nums, int& start, int& end) {
        if (start == end) {return 0;}

        if (end - start == 1) {
            if (nums[end] < nums[start]) {return 1;}
            return 0;
        }

        int i = (end - start + 1) / 2;
        int c = i + start;
        int result = 0;

        if (nums[c] >= nums[end]) {
            result = findOffset(nums, c, end);
            if (result) {return i + result;}
        }

        if (nums[c] <= nums[start]) {
            result = findOffset(nums, start, c);
            if (result) {return result;}
        }

        return result;
    }
};
