class Solution {
public:
    bool isNumber(string s) {
        valid = true;
        sign = false;
        exp = false;
        frac = false;
        num = false;

        for (int i = 0; i < s.size() && valid; i++) {
            if (s[i] == '-' || s[i] == '+') {
                if (sign) {valid = false;}
                else if (num) {valid = false;}
                else if (frac) {valid = false;}
                else {sign = true;}
            }
            else if (s[i] == '.') {
                if (exp) {valid = false;}
                else if (frac) {valid = false;}
                else {frac = true;}
            }
            else if (s[i] == 'e' || s[i] == 'E') {
                if (exp) {valid = false;}
                else if (!num) {valid = false;}
                else {
                    exp = true;
                    num = false;
                    frac = false;
                    sign = false;
                }
            }
            else if (s[i] < '0' || s[i] > '9') {valid = false;}
            else {
                num = true;
            }
        }

        return (valid & num);
    }

private:
    bool valid;
    bool sign;
    bool exp;
    bool frac;
    bool num;
};
