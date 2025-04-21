class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> count;
        unordered_map<int, vector<int>> r;

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for (auto it = count.begin(); it != count.end(); ++it) {
            r[it->second].push_back(it->first);
        }

        for (int i = nums.size(); i > 0; i--) {
            if (!r[i].empty()) {
                for (int j = 0; j < r[i].size(); j++) {result.push_back(r[i][j]);}
            }

            if (result.size() >= k) {break;}
        }

        return result;
    }
};
