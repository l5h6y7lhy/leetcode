class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {return false;}
        if (x < 10) {return true;}
        if (x % 10 == 0) {return false;}

        bSearch(2, 10, x);
        int base = std::pow(10, num_dg - 1);

        while (x != 0) {
            int l = x % 10;
            int h = x / base;

            if (l != h) {return false;}

            x = x - l - (h * base);
            x /= 10;

            base /= 100;
        }

        return true;
    }

private:
    int num_dg;

    void bSearch(int l, int h, int& num) {
        if (h - l == 1) {
            if (num >= std::pow(10, h-1)) {num_dg = h;}
            else {num_dg = l;}
            return;
        }

        int m = (l + h) / 2;

        if (num >= std::pow(10, m)) {
            bSearch(m, h, num);
        }
        else {
            bSearch(l, m, num);
        }
    }
};
