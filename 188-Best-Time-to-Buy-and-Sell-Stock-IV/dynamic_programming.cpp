class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int l = prices.size();
        vector<int> r(l, 0);
        k = min(k, l / 2);

        while (k) {
            int prev = r[l - 1];
            int suffix = prices[l - 1];

            for (int i = l - 2; i >= 0; i--) {
                int curr = max(r[i + 1], suffix - prices[i]);
                suffix = max(suffix, prev + prices[i]);
                prev = r[i];
                r[i] = curr;
            }

            k--;
        }

        return r[0];
    }
};
