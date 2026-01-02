class Solution {
public:
    int candy(vector<int>& ratings) {
        total = 0;
        divide(ratings, 0, ratings.size() - 1);
        return total;
    }

private:
    int total;
    unordered_map<int, int> b;

    void divide(vector<int>& ratings, int l, int r) {
        if (l == r) {
            int cl = (b.find(l - 1) == b.end() ||
                      ratings[l - 1] == ratings[l]) ?
                      1 : b[l - 1] + 1;

            int cr = (b.find(r + 1) == b.end()) ?
                      1 : b[r + 1] + 1;

            total += (b[l] = max(cl, cr));
            return;
        }

        int m = (l + r) / 2;

        if (ratings[m] > ratings[m + 1]) {
            divide(ratings, m + 1, r);
            divide(ratings, l,     m);
        }
        else {
            divide(ratings, l,     m);
            divide(ratings, m + 1, r);
        }

        return;
    }
};
