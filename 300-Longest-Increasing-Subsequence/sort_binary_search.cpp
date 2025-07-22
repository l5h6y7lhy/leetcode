class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        vector<pair<int, int>> r;

        for (int i = 0; i < l; i++) {
            pair<int, int> curr(nums[i], i);
            r.push_back(curr);
        }

        sort(r.begin(), r.end());
        s.push_back(l);

        int i = 0;

        while (1) {
            int prev = r[i].first;
            vector<int> tmp, index;

            while (i < l && r[i].first == prev) {
                p = s.size();
                search(r[i].second, 0, p - 1);

                if (tmp.empty() || p > tmp.back()) {
                    tmp.push_back(p);
                    index.push_back(r[i].second);
                }

                i++;
            }

            for (int j = 0; j < tmp.size(); j++) {
                if (tmp[j] == s.size()) {s.push_back(index[j]);}
                else {s[tmp[j]] = index[j];}
            }

            if (i == l) {break;}
        }

        return s.size();
    }

private:
    int p;
    vector<int> s;

    void search(int& t, int l, int r) {
        if (l > r) {return;}

        int m = (l + r) / 2;

        if (t < s[m]) {
            p = m;
            search(t, l, m - 1);
        }
        else {
            search(t, m + 1, r);
        }
    }
};
