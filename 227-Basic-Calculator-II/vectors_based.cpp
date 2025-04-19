class Solution {
public:
    int calculate(string s) {
        int i = 0, c;
        int curr, tmp;
        string t;
        char operation = '(';
        vector<int> nums, pm;

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

            if (i == s.size()) {
                nums.push_back(curr);
                break;
            }
            i++;

            if (c == 3) {operation = '*';}
            else if (c == 4) {operation = '/';}
            else {
                nums.push_back(curr);
                pm.push_back(c);
                operation = '(';
            }
        }

        curr = nums[0];

        for (i = 0; i < pm.size(); i++) {
            if (pm[i] == 1) {curr += nums[i + 1];}
            else {curr -= nums[i + 1];}
        }

        return curr;
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
