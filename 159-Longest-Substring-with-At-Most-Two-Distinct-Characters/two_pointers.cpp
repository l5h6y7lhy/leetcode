class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {

        int tail;
        int result = 0, cl = 0;
        int d1 = -1, d2 = -1;

        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - '0';

            if (d1 < 0) {
                cl = 1;
                result = 1;
                d1 = curr;
            }
            else if (d2 < 0) {
                cl++;
                result = cl;

                if (d1 != curr) {
                    tail = 1;
                    d2 = curr;
                }
            }
            else {
                int prev = s[i - 1] - '0';

                if (curr == d1 || curr == d2) {
                    cl++;
                    result = max(result, cl);

                    if (curr == prev) {tail++;}
                    else {tail = 1;}
                }
                else {
                    cl = tail + 1;
                    d1 = prev;
                    d2 = curr;
                    tail = 1;
                }
            }
        }

        return result;
    }
};
