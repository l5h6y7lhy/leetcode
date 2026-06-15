class Solution {
public:
    bool isOneEditDistance(string s, string t) {

        int sc = 0, tc = 0;
        int correct = 0;

        while (sc < s.size() || tc < t.size()) {
            if (sc == s.size()) {
                correct++;
                tc++;
            }
            else if (tc == t.size()) {
                correct++;
                sc++;
            }
            else {
                if (s[sc] != t[tc]) {
                    correct++;

                    if (s.size() >= t.size()) {
                        sc++;
                    }

                    if (s.size() <= t.size()) {
                        tc++;
                    }
                }
                else {
                    sc++;
                    tc++;
                }
            }

            if (correct > 1) {break;}
        }

        return (correct == 1);
    }
};
