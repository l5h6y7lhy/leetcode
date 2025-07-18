class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size();
        int suffix = prices[l - 1];
        prices[l - 1] = 0;

        for (int i = l - 2; i >= 0; i--) {
            int curr = suffix - prices[i];
            curr = max(curr, prices[i + 1]);
            suffix = max(suffix, prices[i] + prices[i + 1]);
            prices[i] = curr;
        }

        return prices[0];
    }
};
