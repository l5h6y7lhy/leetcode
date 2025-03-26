class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minimum = prices[0];

        for (int i = 1; i < prices.size(); i++) {
            int tmp = prices[i] - minimum;
            if (tmp > profit) {profit = tmp;}
            if (prices[i] < minimum) {minimum = prices[i];}
        }

        return profit;
    }
};
