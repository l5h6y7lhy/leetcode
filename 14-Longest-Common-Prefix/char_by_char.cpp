class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        int l = strs.size(), p = 0;

        if (l == 1) {return strs[0];}

        while (1) {
            if (p >= strs[0].size()) {break;}

            char c = strs[0][p];
            int i;

            for (i = 1; i < l; i++) {
                if (p >= strs[i].size() || c != strs[i][p]) {break;}
            }

            if (i < l) {break;}
            result += c;
            p++;
        }

        return result;
    }
};
