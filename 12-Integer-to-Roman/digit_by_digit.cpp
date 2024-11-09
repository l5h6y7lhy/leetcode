class Solution {
public:
    string intToRoman(int num) {
        result = "";
        base = 1000;

        while (base) {
            d = num / base;
            num -= (d * base);

            if (d == 4) {
                digit4();
            }
            else if (d == 9) {
                digit9();
            }
            else if (d == 5) {
                digit5();
            }
            else if (d > 5) {
                digit5();
                d -= 5;
                append_digits();
            }
            else {
                append_digits();
            }

            base /= 10;
        }

        return result;
    }

private:
    string result;
    int base;
    int d;

    void digit4() {
        if (base == 1) {result += "IV";}
        else if (base == 10) {result += "XL";}
        else {result += "CD";}
        return;
    }

    void digit9() {
        if (base == 1) {result += "IX";}
        else if (base == 10) {result += "XC";}
        else {result += "CM";}
        return;
    }

    void digit5() {
        if (base == 1) {result += "V";}
        else if (base == 10) {result += "L";}
        else {result += "D";}
        return;
    }

    void append_digits() {
        char a;

        if (base == 1) {a = 'I';}
        else if (base == 10) {a = 'X';}
        else if (base == 100) {a = 'C';}
        else {a = 'M';}

        while(d > 0) {
            result += a;
            d--;
        }

        return;
    }
};
