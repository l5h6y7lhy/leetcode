class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}

        unordered_map<char, int> r;

        for (int i = 0; i < s.size(); i++) {
            r[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++) {
            if (r.find(t[i]) == r.end()) {return false;}

            r[t[i]]--;

            if (!r[t[i]]) {r.erase(t[i]);}
        }

        return true;
    }
};
