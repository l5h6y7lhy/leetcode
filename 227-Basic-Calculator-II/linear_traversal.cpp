class Solution {
public:
    int calculate(string s) {
        int i = 0, c;
        int curr, tmp;
        string t;
        char operation = '(';
        int nums = 0, pm = 1;

        while (1) {
            while (i < s.size() && !(c = isSign(s[i]))) {
                if (s[i] != ' ') {
                    t += s[i];
                }

                i++;
            }

            tmp = stoi(t);
            t = "";

            if (operation == '*') {curr *= tmp;}
            else if (operation == '/') {curr /= tmp;}
            else {curr = tmp;}

            if (c == 3) {operation = '*';}
            else if (c == 4) {operation = '/';}
            else {
                if (pm == 1) {nums += curr;}
                else if (pm == 2) {nums -= curr;}
                operation = '(';
                pm = c;
            }

            if (i == s.size()) {
                break;
            }
            i++;
        }

        return nums;
    }

private:
    int isSign(char& c) {
        if (c == '+') {return 1;}
        if (c == '-') {return 2;}
        if (c == '*') {return 3;}
        if (c == '/') {return 4;}
        return 0;
    }
};
