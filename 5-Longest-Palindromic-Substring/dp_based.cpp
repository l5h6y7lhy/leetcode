class Solution {
public:
    string longestPalindrome(string s) {
        int result = 1;
        int start = 0;
        string ss= "";
        int l = s.size();

        vector<vector<bool>> r;
        r.resize(l);
        for(int i=0; i<l; i++) {
            r[i].resize(l);
            r[i][i] = true;
        }

        for(int j=1; j<l; j++) {
            bool ever = false;

            for(int i=0; i+j<l; i++) {
                if(s[i] == s[i+j] && (j == 1 || r[i+1][i+j-1])) {
                    r[i][i+j] = true;
                    ever = true;
                    start = i;
                }
            }

            if (ever) {result = j + 1;}
        }

        for (int i=0; i<result; i++) {ss.push_back(s[start+i]);}

        return ss;
    }
};
