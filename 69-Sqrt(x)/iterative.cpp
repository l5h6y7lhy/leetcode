class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {return x;}

        int result = 0;
        int curr = 1 << 15;

        while (curr) {
            int t = result + curr;

            if (t <= 46340) {
                int m = t * t;

                if (m == x) {return t;}
                else if (m < x) {
                    result = t;
                }
            }

            curr /= 2;
        }

        return result;
    }
};
