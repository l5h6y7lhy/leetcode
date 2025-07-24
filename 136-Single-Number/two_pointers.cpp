class Solution {
public:
    int singleNumber(vector<int>& nums) {
        curr = 0;
        search(nums);

        int offset = 0;
        vector<bool> eo;

        if (freq == 1) {return minimum;}
        else {
            offset = minimum;
            s -= (minimum * nums.size());

            for (int i = 0; i < nums.size(); i++) {
                nums[i] -= minimum;
            }
        }

        while (1) {
            int l = nums.size() - 1;
            bool even = (s % 2 == 0) ? true : false;
            eo.push_back(even);

            while (curr <= l) {
                if (nums[curr] == 0) {
                    curr++;
                    continue;
                }

                if ((nums[curr] % 2 == 0) == even) {
                    if (curr != l) {
                        nums[curr] ^= nums[l];
                        nums[l] ^= nums[curr];
                        nums[curr] ^= nums[l];
                    }

                    if (!even) {nums[l]--;}
                    nums[l] /= 2;

                    l--;
                }
                else {
                    curr++;
                }
            }

            search(nums);
            if (freq == 1) {break;}
        }

        for (int i = eo.size() - 1; i >= 0; i--) {
            minimum *= 2;
            if (!eo[i]) {minimum += 1;}
        }

        return minimum + offset;
    }

private:
    int s;
    int curr;
    int freq;
    int minimum;

    void search(vector<int>& nums) {
        s = nums[curr];
        freq = 1;
        minimum = nums[curr];

        for (int i = curr + 1; i < nums.size(); i++) {
            s += nums[i];

            if (nums[i] < minimum) {
                minimum = nums[i];
                freq = 1;
            }
            else if (nums[i] == minimum) {
                freq++;
            }
        }

        return;
    }
};
