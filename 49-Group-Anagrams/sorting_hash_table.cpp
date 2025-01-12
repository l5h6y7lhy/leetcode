class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> r;

        for (int i = 0; i < strs.size(); i++) {
            l = strs[i].size();
            curr = strs[i];

            for (int j = l / 2; j > 0; j--) {heapifyDown(j);}

            while(l > 1) {
                curr[l - 1] ^= curr[0];
                curr[0] ^= curr[l - 1];
                curr[l - 1] ^= curr[0];
                l--;
                heapifyDown(1);
            }

            if (r.find(curr) == r.end()) {
                r[curr] = result.size();
                result.resize(result.size() + 1);
            }

            result[r[curr]].push_back(strs[i]);
        }

        return result;
    }

private:
    int l;
    string curr;

    void heapifyDown(int index) {
        int c = curr[index - 1];

        if (index <= (l/2)) {
            int left = curr[(2 * index) - 1];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = curr[2 * index];
            }

            if (left <= right && c > left) {
                curr[index - 1] ^= curr[(2 * index) - 1];
                curr[(2 * index) - 1] ^= curr[index - 1];
                curr[index - 1] ^= curr[(2 * index) - 1];
                heapifyDown(2 * index);
            }
            else if (left > right && c > right) {
                curr[index - 1] ^= curr[2 * index];
                curr[2 * index] ^= curr[index - 1];
                curr[index - 1] ^= curr[2 * index];
                heapifyDown((2 * index) + 1);
            }
        }

        return;
    }
};
