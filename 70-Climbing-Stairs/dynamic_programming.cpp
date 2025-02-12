class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {return 1;}

        int r[n + 1];
        r[0] = 1;
        r[1] = 1;

        for (int i = 2; i <= n; i++) {
            r[i] = r[i - 1] + r[i - 2];
        }

        return r[n];
    }
};
