class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = 1;
        bool start = false;
        int nzd = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ' && !start) {
                continue;
            }

            if ((s[i] == '-' || s[i] == '+') && !start) {
                sign = (s[i] == '+') ? 1 : -1;
                start = true;
                continue;
            }

            if (s[i] < '0' || s[i] > '9') {break;}
            start = true;

            if (s[i] == '0' && !nzd) {continue;}

            if (nzd == 10) {
                return (sign > 0) ? INT_MAX : INT_MIN;
            }

            int dg = s[i] - '0';

            if (nzd == 9) {
                if ((result > 214748364) ||
                    (result == 214748364 && dg > 7)) {
                    return INT_MAX;
                }

                if ((result < -214748364) ||
                    (result == -214748364 && dg > 8)) {
                    return INT_MIN;
                }
            }

            result = (10 * result) + (sign * dg);
            nzd++;
        }

        return result;
    }
};
