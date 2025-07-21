class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> p(prices.size());
        p.push_back(0);

        for (int i = p.size() - 2; i >= 0; i--) {
            int curr = 0;

            for (int j = i; j < p.size() - 1; j++) {
                int tmp = prices[j] - prices[i] + p[j + 1];
                if (tmp > curr) {curr = tmp;}
            }

            p[i] = curr;
        }

        return p[0];
    }
};
