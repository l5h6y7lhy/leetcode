class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bitr(32, 0);

        for (int i = 0; i < nums.size(); i++) {
            unsigned int curr = static_cast<unsigned int>(nums[i]);

            int b = 0;

            while (curr) {
                if (curr % 2 == 1) {bitr[b]++;}

                b++;
                curr = curr >> 1;
            }
        }

        unsigned int result = 0;
        unsigned int curr_b = 1;

        for (int i = 0; i < 32; i++) {
            if (bitr[i] % 2 == 1) {result += curr_b;}
            curr_b = curr_b << 1;
        }

        return static_cast<int>(result);
    }
};
