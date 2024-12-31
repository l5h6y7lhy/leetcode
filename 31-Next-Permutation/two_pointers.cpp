class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = nums.size() - 1;

        while (left > 0) {
            if (nums[left - 1] < nums[left]) {break;}
            left--;
        }

        int i1 = left;
        int i2 = nums.size() - 1;

        while (i1 < i2) {
            nums[i1] ^= nums[i2];
            nums[i2] ^= nums[i1];
            nums[i1] ^= nums[i2];
            i1++;
            i2--;
        }

        if (!left) {return;}

        i1 = left;

        while (i1 < nums.size() - 1) {
            if (nums[left - 1] < nums[i1]) {break;}
            i1++;
        }

        nums[i1] ^= nums[left - 1];
        nums[left - 1] ^= nums[i1];
        nums[i1] ^= nums[left - 1];

        return;
    }
};
