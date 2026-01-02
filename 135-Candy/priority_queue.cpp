class Solution {
public:
    struct lncomparison
    {
        const vector<int>& r;

        lncomparison(const vector<int>& ratings): r(ratings)
        {}

        bool operator() (int lhs, int rhs) const
        {
            if (r[lhs] < r[rhs]) {return false;}
            if (r[lhs] > r[rhs]) {return true;}
            return lhs > rhs;
        }
    };

    int candy(vector<int>& ratings) {
        int result = 0;

        lncomparison tl(ratings);
        priority_queue<int, vector<int>, lncomparison> q(tl);

        for (int i = 0; i < ratings.size(); i++) {q.push(i);}

        int left = -1, right = -1;
        unordered_map<int, int> b;

        while (1) {
            int curr = q.top();
            q.pop();

            if (left < 0) {
                left = curr;
                right = curr;
            }
            else if (left - curr == 1) {
                left = curr;
            }
            else if (curr - right == 1) {
                right = curr;
            }

            if (q.empty() ||
                left - q.top() > 1 ||
                q.top() - right > 1 ||
                ratings[left] != ratings[q.top()]) {
                int total = 0;

                int cl = (b.find(left - 1) == b.end()) ? 1 : b[left - 1] + 1;
                int cr = (b.find(right + 1) == b.end()) ? 1 : b[right + 1] + 1;

                if (right > left) {
                    total += cl + cr + right - left - 1;
                    b[left] = cl;
                    b[right] = cr;
                }
                else {
                    total += (b[left] = max(cl, cr));
                }

                result += total;
                left = -1;
                right = -1;
            }

            if (q.empty()) {break;}
        }

        return result;
    }
};
