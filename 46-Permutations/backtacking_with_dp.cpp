class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> prev, curr;
        vector<int> p;

        p.push_back(nums[0]);
        prev.push_back(p);

        for (int i = 1; i < nums.size(); i++) {
            int c = nums[i];

            for (int j = 0; j < prev.size(); j++) {
                for (int k = 0; k <= i; k++) {
                    p = prev[j];
                    p.insert(p.begin() + k, c);
                    curr.push_back(p);
                }
            }

            prev = curr;
            curr.resize(0);
        }

        return prev;
    }
};
