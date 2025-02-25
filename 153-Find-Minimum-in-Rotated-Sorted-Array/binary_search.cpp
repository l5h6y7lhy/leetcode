class Solution {
public:
    int findMin(vector<int>& nums) {
        offset = 0;

        int start = 0;
        l = nums.size();
        int end = l - 1;
        findOffset(nums, start, end);

        return nums[offset];
    }

private:
    int offset;
    int l;
    int result;

    void findOffset(vector<int>& nums, int& start, int& end) {
        if (start == end) {return;}

        if (end - start == 1) {
            if (nums[end] < nums[start]) {offset++;}
            return;
        }

        int i = (end - start + 1) / 2;
        int c = i + start;

        if (nums[c] > nums[end]) {
            offset += i;
            findOffset(nums, c, end);
        }
        else {
            findOffset(nums, start, c);
        }

        return;
    }
};
