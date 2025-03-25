class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) {return 0;}

        int maximum = 0;
        vector<int> copy = nums, digits(10, 0);
        vector<int> p1, p2(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maximum) {maximum = nums[i];}
            p1.push_back(i);
        }

        int times = 0;

        while (maximum) {
            times++;
            maximum = maximum / 10;
        }

        for (int i = 0; i < times; i++) {
            for (int j = 0; j < copy.size(); j++) {
                digits[copy[j] % 10]++;
            }

            digits[0]--;

            for (int j = 1; j < 10; j++) {
                digits[j] += digits[j - 1];
            }

            for (int j = p1.size() - 1; j >= 0; j--) {
                p2[digits[copy[p1[j]] % 10]] = p1[j];
                digits[copy[p1[j]] % 10]--;
                copy[p1[j]] /= 10;
            }

            p1 = p2;
            digits.assign(10, 0);
        }

        int diff = 0;

        for (int i = 1; i < p1.size(); i++) {
            int tmp = nums[p1[i]] - nums[p1[i - 1]];
            if (tmp > diff) {diff = tmp;}
        }

        return diff;
    }
};
