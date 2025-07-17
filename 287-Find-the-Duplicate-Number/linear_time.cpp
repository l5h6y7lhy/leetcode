class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        bool search = false;
        int i = 0, previ;
        int val = nums[i];
        int result, origin;

        while (1) {
            if (i == nums.size() - 1) {
                result = val;
                break;
            }

            if (val <= 0) {
                if (search) {
                    result = i + 1;

                    val = nums[previ] * (-1);
                    nums[previ] = result;
                    i = val;
                    val = previ + 1;

                    while (i >= 0) {
                        int tmp = nums[i] * (-1);
                        nums[i] = val;
                        val = i + 1;
                        i = tmp;
                    }

                    break;
                }

                i++;
                val = nums[i];
                continue;
            }

            if (!search) {
                origin = i;
                search = true;
            }

            if (search && val - 1 == origin) {
                search = false;
            }

            int tmp = nums[val - 1];
            if (tmp > 0) {nums[val - 1] = (-1) * i;}
            previ = i;
            i = val - 1;
            val = search ? tmp : nums[i];
        }

        i = 0;
        val = nums[i];

        while (1) {
            if (i == nums.size() - 1) {
                break;
            }

            if (val > 0) {
                i++;
                val = nums[i];
                continue;
            }

            if (!search) {
                origin = i;
                search = true;
            }

            int p = val * (-1);

            if (search && p == origin) {
                search = false;
            }

            int tmp = nums[p];
            nums[p] = i + 1;
            i = p;
            val = search ? tmp : nums[p];
        }

        return result;
    }
};
