class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        nums.push_back(10001);
        int l = nums.size();

        vector<vector<int>> r;
        r.resize(l);

        for (int i = 0; i < nums.size(); i++) {
            r[i].resize(l, 0);
        }

        for (int i = 1; i < l; i++) {
            for (int j = i; j < l; j++) {
                int m = r[i - 1][j];

                if (nums[i - 1] < nums[j]) {
                    m = max(m, 1 + r[i - 1][i - 1]);
                }

                r[i][j] = m;
            }
        }

        return r[l - 1][l - 1];
    }
};
