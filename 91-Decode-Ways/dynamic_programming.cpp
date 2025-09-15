class Solution {
public:
    int numDecodings(string s) {
        int l = s.size();
        vector<int> r(l + 1, 1);

        for (int i = l - 1; i >= 0; i--) {
            int curr = 0;

            if (s[i] != '0') {
                curr += r[i + 1];
            }

            if (i < l - 1) {
                if (s[i] == '1') {
                    curr += r[i + 2];
                }
                else if (s[i] == '2' && s[i + 1] < '7') {
                    curr += r[i + 2];
                }
            }

            r[i] = curr;
        }

        return r[0];
    }
};