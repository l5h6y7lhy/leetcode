class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (!amount) {return 0;}

        sort(coins.begin(), coins.end());
        if (amount < coins[0]) {return -1;}

        int r[coins.size()][amount + 1];

        for (int i = 0; i < coins.size(); i++) {
            for (int j = 0; j < coins[0]; j++) {
                if (j == 0) {r[i][j] = 0;}
                else {r[i][j] = -1;}
            }
        }

        for (int j = coins[0]; j <= amount; j++) {
            for (int i = 0; i < coins.size(); i++) {
                int l1, l2;

                if (i > 0) {l1 = r[i - 1][j];}
                else {l1 = -1;}

                if (j >= coins[i]) {l2 = r[i][j - coins[i]];}
                else {l2 = -1;}

                if (l1 < 0 && l2 < 0) {r[i][j] = -1;}
                else if (l1 < 0) {r[i][j] = l2 + 1;}
                else if (l2 < 0) {r[i][j] = l1;}
                else {r[i][j] = min(l1, l2 + 1);}
            }
        }

        return r[coins.size() - 1][amount];
    }
};
