class Solution {
public:
    bool makePalindrome(string s) {
        int c = 0;
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {
                if (c >= 2) {break;}
                c++;
            }
            i++;
            j--;
        }

        return (i >= j);
    }
};
