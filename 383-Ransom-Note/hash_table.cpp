class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> r;

        for (int i = 0; i < magazine.size(); i++) {
            r[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if ((--r[ransomNote[i]]) < 0) {return false;}
        }

        return true;
    }
};
