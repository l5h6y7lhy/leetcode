class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        sign = 1;
        bool start = false;
        nzd = 0;
        v = 2;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (start) {break;}
                continue;
            }

            if (s[i] == '-' && !start) {
                sign = -1;
                start = true;
                continue;
            }

            if (s[i] == '+' && !start) {
                start = true;
                continue;
            }

            if (s[i] < '0' || s[i] > '9') {break;}
            start = true;

            if (s[i] == '0' && !nzd) {continue;}

            if (nzd == 10) {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }

            if (v == 2) {determine(s[i]);}

            if (nzd == 9 && v == 1) {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }

            int dg = s[i] - '0';
            result = (10 * result) + (sign * dg);
            nzd++;
        }

        return result;
    }

private:
    int nzd;
    int v;
    int sign;
    int book[9] = {2, 1, 4, 7, 4, 8, 3, 6, 4};

    void determine(char& digit) {
        int dg = digit - '0';
        int threshold;

        if (nzd == 9) {
            threshold = (sign > 0) ? 7 : 8;
        }
        else {
            threshold = book[nzd];
        }

        if (dg < threshold) {v = 0;}
        else if(dg > threshold) {v = 1;}

        return;
    }
};
