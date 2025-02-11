class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {return x;}
        binarySearch(x, 1, 46340);
        return result;
    }

private:
    int result;

    void binarySearch(int& x, int l, int r) {
        if (l > r) {return;}

        if (l == r) {
            if (l * l <= x) {result = l;}
            return;
        }

        int m = (l + r) / 2;
        int t = m * m;

        if (x == t) {
            result = m;
            return;
        }

        if (x < t) {
            binarySearch(x, l, m - 1);
        }
        else {
            result = m;
            binarySearch(x, m + 1, r);
        }

        return;
    }
};
