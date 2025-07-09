class Solution {
public:
    struct pair_hash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };

    int coinChange(vector<int>& coins, int amount) {
        if (!amount) {return 0;}

        sort(coins.begin(), coins.end());
        if (amount < coins[0]) {return -1;}

        queue<tuple<int, int, int>> r;
        unordered_set<pair<int, int>, pair_hash> e;

        r.push(tuple<int, int, int>(coins.size(), amount, 0));

        while (!r.empty()) {
            tuple<int, int, int> curr = r.front();
            r.pop();

            int index  = get<0>(curr);
            int remain = get<1>(curr);
            int step   = get<2>(curr);

            for (int i = 0; i < index; i++) {
                if (remain < coins[i]) {continue;}
                if (remain == coins[i]) {return step + 1;}

                pair<int, int> comb(i + 1, remain - coins[i]);

                if (e.find(comb) == e.end()) {
                    e.insert(comb);

                    get<0>(curr) = i + 1;
                    get<1>(curr) = remain - coins[i];
                    get<2>(curr) = step + 1;

                    r.push(curr);
                }
            }
        }

        return -1;
    }
};
