class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSelect(nums, k);
    }

private:
    int QuickSelect(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return nums[0];
        }

        vector<int> left, right;
        int c = nums.size() / 2;
        int c_count = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (i == c) {continue;}
            if (nums[i] < nums[c]) {left.push_back(nums[i]);}
            else if (nums[i] > nums[c]) {right.push_back(nums[i]);}
            else {c_count++;}
        }

        if (right.size() >= k) {
            return QuickSelect(right, k);
        }
        else if (right.size() + c_count >= k) {return nums[c];}

        return QuickSelect(left, k - right.size() - c_count);
    }
};
