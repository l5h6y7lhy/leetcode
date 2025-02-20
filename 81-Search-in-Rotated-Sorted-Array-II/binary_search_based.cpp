class Solution {
public:
    bool search(vector<int>& nums, int target) {
        l = nums.size();
        int start = 0;
        int end = l - 1;

        offset = findOffset(nums, start, end);

        result = false;
        binarySearch(nums, target, start, end);

        return result;
    }

private:
    int offset;
    int l;
    bool result;

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

    void binarySearch(vector<int>& nums, int& target, int& start, int& end) {
        if (end < start) {return;}

        int c1 = (start + offset) % l;
        int c2 = (end + offset) % l;

        int middle = (start + end) / 2;
        int c3 = (middle + offset) % l;

        if (target > nums[c3]) {
            binarySearch(nums, target, ++middle, end);
        }
        else if (target < nums[c3]) {
            binarySearch(nums, target, start, --middle);
        }
        else {
            result = true;
        }

        return;
    }
};
