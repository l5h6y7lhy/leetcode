class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, vector<int>> record;
        int result = 0, c = 0;

        for (int i=0; i<s.size(); i++) {
            int l = (record[s[i]].empty()) ? -1 : record[s[i]].back();

            if (l < i - c) {
                c++;
            }
            else {
                c = i - l;
            }

            record[s[i]].push_back(i);
            if (c > result) {result = c;}
        }

        return result;
    }
};
