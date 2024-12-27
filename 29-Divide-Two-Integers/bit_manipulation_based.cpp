class Solution {
public:
    int divide(int dividend, int divisor) {

        bool positive = true;

        if (divisor < 0) {
            if (dividend > 0) {
                positive = false;
                dividend = 0 - dividend;
            }
        }
        else {
            divisor = 0 - divisor;
            if (dividend < 0) {positive = false;}
            else {dividend = 0 - dividend;}
        }

        int result = find(dividend, divisor);

        if (positive) {
            if (result == INT_MIN) {return INT_MAX;}
            return 0 - result;
        }

        return result;
    }

private:
    int find(int dividend, int divisor) {
        if (divisor < dividend) {return 0;}

        int curr = divisor;
        int f = -1;

        while (dividend - curr <= curr) {
            f = f << 1;
            curr = curr << 1;
        }

        return f + find(dividend - curr, divisor);
    }
};
