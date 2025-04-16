class Solution {
public:
    int maximumSwap(int num) {
        if (num < 12) {return num;}

        int maximum = 0;
        string s;
        unordered_map<int, int> r;

        while (num) {
            int c = num % 10;
            if (r.find(c) == r.end()) {r[c] = s.size();}
            s.push_back('0' + c);
            if (c > maximum) {maximum = c;}
            num = num / 10;
        }

        int i = s.size() - 1;

        while (i >= 0 && maximum > 0) {
            int num = s[i] - '0';

            if (num == maximum) {
                i--;
                continue;
            }

            if (i < r[maximum]) {
                do {
                    maximum--;
                } while (maximum > 0 && r.find(maximum) == r.end());
                continue;
            }

            char tmp = s[i];
            s[i] = s[r[maximum]];
            s[r[maximum]] = tmp;
            break;
        }

        std::reverse(s.begin(), s.end());
        return std::atoi(s.c_str());
    }
};
