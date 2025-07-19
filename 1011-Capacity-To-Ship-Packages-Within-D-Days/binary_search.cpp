class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int maximum = 0;

        for (int i = 0; i < weights.size(); i++) {
            sum += weights[i];
            if (weights[i] > maximum) {maximum = weights[i];}
        }

        search(weights, days, maximum, sum);

        return result;
    }

private:
    int result;

    void search(vector<int>& weights, int& days, int l, int r) {
        if (r < l) {return;}

        int c = 0;
        int w = 0;
        int m = (l + r) / 2;

        for (int i = 0; i < weights.size(); i++) {
            if (w + weights[i] > m) {
                c++;
                w = weights[i];

                if (c == days) {break;}
            }
            else {w += weights[i];}
        }

        c++;

        if (c <= days) {
            result = m;
            search(weights, days, l, m - 1);
        }
        else {
            search(weights, days, m + 1, r);
        }
    }
};
