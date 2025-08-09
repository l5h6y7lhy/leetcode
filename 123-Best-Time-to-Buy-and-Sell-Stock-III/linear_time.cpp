class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int oneP = 0;
        int result = 0;
        int cm = prices.back();
        int maximum = prices.back();

        for (int i = prices.size() - 2; i >= 0; i--) {
            result = max(result, cm - prices[i]);
            cm = max(cm, prices[i] + oneP);
            oneP = max(oneP, maximum - prices[i]);
            maximum = max(maximum, prices[i]);
        }

        return result;
    }
};
