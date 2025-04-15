class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (!alphanumeric(s[i])) {
                i++;
                continue;
            }

            if (!alphanumeric(s[j])) {
                j--;
                continue;
            }

            if (s[i] != s[j]) {return false;}
            i++;
            j--;
        }

        return true;
    }

private:
    bool alphanumeric(char& c) {
        if (c >= 'A' && c <= 'Z') {
            c += 32;
            return true;
        }

        if (c >= 'a' && c <= 'z') {return true;}
        if (c >= '0' && c <= '9') {return true;}
        return false;
    }
};
