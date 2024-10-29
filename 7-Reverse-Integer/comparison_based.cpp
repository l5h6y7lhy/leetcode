class Solution {
public:
    int reverse(int x) {
        int result = 0;
        int step = 0;

        while (step < 10 && x) {
            int digit = x % 10;

            if (step == 9 &&
               (result > 214748364 ||
                result < -214748364)) {
                return 0;
            }

            result = (result * 10) + digit;
            x /= 10;
            step++;
        }

        return result;
    }
};
