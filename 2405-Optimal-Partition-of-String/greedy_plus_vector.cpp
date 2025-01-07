class Solution {
public:
    int partitionString(string s) {
        int result = 0;
        vector<bool> r(26, false);

        for (int i = 0; i < s.size(); i++) {
            if (r[s[i] - 'a']) {
                result++;
                r.assign(26, false);
            }
            r[s[i] - 'a'] = true;
        }
        return result + 1;
    }
};
