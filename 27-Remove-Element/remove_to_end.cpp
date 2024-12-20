class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = nums.size();
        int left = 0;
        int right = l - 1;

        while (left <= right) {
            if (nums[left] != val) {left++;}
            else {
                nums[left] ^= nums[right];
                nums[right] ^= nums[left];
                nums[left] ^= nums[right];

                right--;
            }
        }

        return left;
    }
};
