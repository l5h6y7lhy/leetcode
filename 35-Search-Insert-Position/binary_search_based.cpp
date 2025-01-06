class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        start = 0;
        end = nums.size() - 1;
        return binarySearch(nums, target);
    }

private:
    int start;
    int end;

    int binarySearch(vector<int>& nums, int& target) {
        if (end < start) {return start;}

        if (start == end) {
            if (nums[start] == target) {return start;}
            else if (nums[start] > target) {return start;}
            else {return start + 1;}
        }

        int middle = (start + end) / 2;

        if (nums[middle] == target) {return middle;}
        else if (nums[middle] > target) {end = middle - 1;}
        else {start = middle + 1;}

        return binarySearch(nums, target);
    }
};
