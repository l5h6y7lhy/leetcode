class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ms = 0;

        for (int i = 0; i < piles.size(); i++) {
            if (piles[i] > ms) {ms = piles[i];}
        }

        search(piles, h, 1, ms);

        return result;
    }

private:
    int result;

    void search(vector<int>& piles, int& h, int l, int r) {
        if (r < l) {return;}

        bool exceed = false;
        int steps = 0;
        int m = (l + r) / 2;

        for (int i = 0; i < piles.size(); i++) {
            int remain = 0;
            if (piles[i] % m != 0) {remain = 1;}

            int cs = (piles[i] / m) + remain;

            if (h - steps >= cs) {steps += cs;}
            else {
                exceed = true;
                break;
            }
        }

        if (!exceed) {
            result = m;
            search(piles, h, l, m - 1);
        }
        else {
            search(piles, h, m + 1, r);
        }

        return;
    }
};
