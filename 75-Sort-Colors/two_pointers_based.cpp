class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = nums.size();
        int pl = 0;
        int pr = l - 1;
        int ml = pr / 2;
        int mr = ml + 1;

        while (1) {
            if (pr <= pl) {break;}
            if (ml < pl && mr > pr) {break;}

            if (pl > mr || pr < ml) {
                ml = (pl + pr) / 2;
                mr = ml + 1;
            }

            if (nums[pl] > nums[pr]) {
                nums[pl] ^= nums[pr];
                nums[pr] ^= nums[pl];
                nums[pl] ^= nums[pr];
            }

            if (nums[pl] == 0) {
                pl++;
                continue;
            }

            if (nums[pr] == 2) {
                pr--;
                continue;
            }

            if (ml >= 0 && nums[ml] == 1) {
                ml--;
                continue;
            }

            if (mr < l && nums[mr] == 1) {
                mr++;
                continue;
            }

            if (ml > pl && nums[ml] == 0) {
                nums[ml] ^= nums[pl];
                nums[pl] ^= nums[ml];
                nums[ml] ^= nums[pl];
                pl++;
                continue;
            }

            if (ml >= 0 && nums[ml] == 2) {
                nums[ml] ^= nums[pr];
                nums[pr] ^= nums[ml];
                nums[ml] ^= nums[pr];
                pr--;
                continue;
            }

            if (mr < l && nums[mr] == 0) {
                nums[mr] ^= nums[pl];
                nums[pl] ^= nums[mr];
                nums[mr] ^= nums[pl];
                pl++;
                continue;
            }

            if (mr < pr && nums[mr] == 2) {
                nums[mr] ^= nums[pr];
                nums[pr] ^= nums[mr];
                nums[mr] ^= nums[pr];
                pr--;
                continue;
            }
        }

        return;
    }
};
