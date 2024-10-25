class Solution {
public:
    int reverse(int x) {
        int result = 0;

        step = 0;
        v = 2;

        while (step < 10 && x) {
            int digit = x % 10;

            if (step == 9 && v == 1) {return 0;}
            if (step < 9 && v == 2) {determine(digit);}

            result = (result * 10) + digit;
            x /= 10;
            step++;
        }

        return result;
    }

private:
    int step;
    int v;
    int book[9] = {2, 1, 4, 7, 4, 8, 3, 6, 4};

    void determine(int& digit) {
        int dg = digit;
        if (dg < 0) {dg *= (-1);}

        if (dg < book[step]) {v = 0;}
        else if(dg > book[step]) {v = 1;}

        return;
    }
};
