class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> record;
        int result = 0, c = 0;

        for (int i=0; i<s.size(); i++) {
            int l = (record.find(s[i]) == record.end()) ? -1 : record[s[i]];

            if (l < i - c) {
                c++;
            }
            else {
                c = i - l;
            }

            record[s[i]] = i;
            if (c > result) {result = c;}
        }

        return result;
    }
};
