class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = s.size();
        int result = 0;

        for (int i = l - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (!result) {continue;}
                break;
            }

            result++;
        }

        return result;
    }
};
