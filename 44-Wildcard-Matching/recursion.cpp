class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        ls = s.size();
        lp = p.size();

        while (i < ls && j < lp) {
            if (s[i] != p[j] && p[j] != '?') {
                if (p[j] == '*') {break;}
                return false;
            }
            i++;
            j++;
        }

        if (j == lp) {
            return (i == ls);
        }

        if (i == ls && p[j] != '*') {return false;}

        result = 0;
        MatchCheck(s, p, i, j);

        return (result == 1);
    }

private:
    int ls, lp;
    int result;

    void MatchCheck(string& s, string& p, int& i, int& j) {
        int pi = i;
        int pj = j + 1;

        if (pj == lp) {
            result = 1;
            return;
        }

        if (p[pj] == '*') {
            MatchCheck(s, p, pi, pj);
            return;
        }

        if (pi == ls) {
            result = 2;
            return;
        }

        while (pi < ls) {
            bool match = true;
            int ti = pi;
            int tj = pj;

            while (ti < ls && tj < lp) {
                if (s[ti] != p[tj] && p[tj] != '?') {
                    if (p[tj] == '*') {break;}
                    match = false;
                    break;
                }
                ti++;
                tj++;
            }

            if (!match) {
                pi++;
                continue;
            }

            if (tj == lp) {
                if (ti == ls) {
                    result = 1;
                    return;
                }
                pi++;
                continue;
            }

            if (ti == ls && p[tj] != '*') {
                result = 2;
                return;
            }

            MatchCheck(s, p, ti, tj);

            if (result > 0) {return;}
            pi++;
        }

        return;
    }
};
