class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        return build(coins, amount, coins.size() - 1);
    }

private:
    unordered_map<pair<int, int>, int, pair_hash> book;

    int build(vector<int>& coins, int amount, int l) {
        if (!amount) {return 0;}
        if (l < 0) {return -1;}
        if (amount < coins[0]) {return -1;}

        pair<int, int> currp(amount, l);

        if (book.find(currp) != book.end()) {return book[currp];}

        int l1 = build(coins, amount, l - 1);
        int l2 = build(coins, amount - coins[l], l);
        int result;

        if (l1 < 0 && l2 < 0) {result = -1;}
        else if (l1 < 0) {result = l2 + 1;}
        else if (l2 < 0) {result = l1;}
        else {result = min(l1, l2 + 1);}

        return (book[currp] = result);
    }
};
