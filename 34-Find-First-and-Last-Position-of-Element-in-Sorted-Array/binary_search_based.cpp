class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        result.push_back(-1);
        result.push_back(-1);

        if (nums.empty()) {return result;}

        limit = 0;
        start = 0;
        end = nums.size() - 1;
        binarySearch(nums, target);

        limit = 1;
        start = 0;
        end = nums.size() - 1;
        binarySearch(nums, target);

        return result;
    }

private:
    vector<int> result;
    int limit;
    int start;
    int end;

    void binarySearch(vector<int>& nums, int& target) {
        if (end < start) {return;}

        int middle = (start + end) / 2;

        if (nums[middle] == target) {
            result[limit] = middle;

            if (!limit) {end = middle - 1;}
            else {start = middle + 1;}
        }
        else if (nums[middle] >= target) {
            end = middle - 1;
        }
        else {
            start = middle + 1;
        }

        binarySearch(nums, target);
        return;
    }
};
