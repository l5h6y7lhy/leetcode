class Solution {
public:
    vector<string> generateParenthesis(int n) {
        r[1].push_back("()");
        pivot.resize(9);
        pivot[1] = 0;

        for (int i = 2; i <= n; i++) {

            for (int j = 0; j < r[i-1].size(); j++) {
                r[i].push_back("(" + r[i-1][j] + ")");
            }

            target = 0;
            t = "";

            pivot[i] = r[i].size();
            construct(i, false);
        }

        return r[n];
    }

private:
    unordered_map<int, vector<string>> r;
    vector<int> pivot;
    int target;
    string t;

    void construct(int& n, bool record) {
        if (target == n) {
            r[n].push_back(t);
            return;
        }

        if (!record) {
            string pa = "";
            for (int i = 0; target + i <= n; i++) {
                target += i;
                t += pa;
                construct(n, true);
                target -= i;
                t.resize(2 * target);
                pa += "()";
            }
        }
        else {
            for (int i = 2; i < n; i++) {
                if (target + i > n) {break;}

                for (int j = 0; j < pivot[i]; j++) {
                    target += i;
                    t += r[i][j];
                    construct(n, false);
                    target -= i;
                    t.resize(2 * target);
                }
            }
        }
    }
};
