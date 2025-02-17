class Solution {
public:
    int search(vector<int>& nums, int target) {
        offset = 0;

        int start = 0;
        l = nums.size();
        int end = l - 1;
        findOffset(nums, start, end);

        result = -1;
        binarySearch(nums, target, start, end);

        return result;
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
            result = c3;
        }

        return;
    }
};
