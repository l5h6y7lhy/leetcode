class Solution {
public:
    vector<string> generateParenthesis(int n) {
        r[0].push_back("");
        pivot.resize(9);

        for (int i = 1; i <= n; i++) {

            for (int j = 0; j < r[i-1].size(); j++) {
                r[i].push_back("(" + r[i-1][j] + ")");
            }

            target = 0;
            t = "";

            pivot[i] = r[i].size();
            construct(i);
        }

        return r[n];
    }

private:
    unordered_map<int, vector<string>> r;
    vector<int> pivot;
    int target;
    string t;

    void construct(int& n) {
        if (target == n) {
            r[n].push_back(t);
            return;
        }

        for (int i = 1; i < n; i++) {
            if (target + i > n) {break;}

            for (int j = 0; j < pivot[i]; j++) {
                target += i;
                t += r[i][j];
                construct(n);
                target -= i;
                t.resize(2 * target);
            }
        }
    }
};
