class Solution {
public:
    string longestPalindrome(string s) {
        int result = 1;
        int start = 0;
        string ss= "";
        len = s.size();

        for (int i = 0; i < len; i++) {
            int l1 = std::max(maxL(s, i, i), maxL(s, i, i+1));

            if (l1 > result) {
                result = l1;
                start = i - ((l1 - 1) / 2);
            }

        }

        for (int i=0; i<result; i++) {ss.push_back(s[start+i]);}

        return ss;
    }

private:
    int len;

    int maxL(string& s, int l, int r) {

        while(l >= 0 && r < len && s[l] == s[r]) {
            l--;
            r++;
        }

        return r-l-1;
    }
};
