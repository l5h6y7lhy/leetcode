class Solution {
public:
    bool isValid(string s) {
        int l = s.size();
        vector<char> r;

        for (int i = 0; i < l; i++) {
            char c = s[i];

            if (c == '(' || c == '[' || c == '{') {
                r.push_back(c);
                continue;
            }

            if (r.empty()) {return false;}

            int d = ((int) c) - ((int) r.back());

            if (d != 1 && d != 2) {return false;}

            r.pop_back();
        }

        return r.empty();
    }
};
