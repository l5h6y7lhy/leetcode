class Solution {
public:
    string shortestPalindrome(string s) {
        int l = s.size();
        if (l < 2) {return s;}

        lps.push_back(0);
        f = 0;
        int b = l - 1;

        string pre;
        int push_p = l - 1;

        while (b >= f) {
            if (s[b] == s[f]) {
                b--;
                f++;
                continue;
            }

            if (!f) {
                b--;
                pre.push_back(s[push_p]);
                push_p--;
                continue;
            }

            if (f > lps.size()) {build(s);}

            int prev = f;
            f = lps[f - 1];

            for (int i = 0; i < prev - f; i++) {
                pre.push_back(s[push_p]);
                push_p--;
            }
        }

        return pre + s;
    }

private:
    vector<int> lps;
    int f;

    void build(string& s) {
        while (lps.size() < f) {
            int len  = lps.size();
            int last = lps.back();

            if (s[len] == s[last]) {
                lps.push_back(last + 1);
                continue;
            }

            while (1) {
                if (s[len] == s[last]) {
                    lps.push_back(last + 1);
                    break;
                }

                if (!last) {
                    lps.push_back(0);
                    break;
                }

                last = lps[last - 1];
            }
        }

        return;
    }
};
