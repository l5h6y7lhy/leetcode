class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (curr < 2 || nums[i] != nums[curr - 2]) {
                nums[curr] = nums[i];
                curr++;
            }
        }

        return curr;
    }
};
