class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<vector<int>> r;

        vector<int> alphabet;
        alphabet.resize(26);

        for (int i = 0; i < strs.size(); i++) {
            alphabet.assign(26, 0);

            for (int j = 0; j < strs[i].size(); j++) {
                alphabet[strs[i][j] - 'a']++;
            }

            int k;

            for (k = 0; k < r.size(); k++) {
                if (r[k] == alphabet) {break;}
            }

            if (k == r.size()) {
                r.push_back(alphabet);
                result.resize(result.size() + 1);
            }

            result[k].push_back(strs[i]);
        }

        return result;
    }
};
