class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> r;
        for (int i = 0; i < wordDict.size(); i++) {r[wordDict[i]] = true;}

        vector<bool> b(20, false);
        b[0] = true;
        int p = 1;
        int count = 1;

        for (int j = s.size() - 1; j >= 0; j--) {
            if (!count) {return false;}

            int len = (s.size() - j > 20) ? 20 : s.size() - j;
            string tmp = s.substr(j, len);

            bool cp = false;

            while (!tmp.empty()) {
                if (r[tmp] && b[(p - len + 20) % 20]) {
                    cp = true;
                    break;
                }
                len--;
                tmp.pop_back();
            }

            if (cp != b[p]) {
                if (cp) {count++;}
                else {count--;}
            }

            b[p] = cp;

            p = (p + 1) % 20;
        }

        return b[(p - 1 + 20) % 20];
    }
};
