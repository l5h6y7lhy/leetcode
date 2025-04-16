class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j]) {break;}
            i++;
            j--;
        }

        if (i >= j) {return true;}

        return (PalindromeCheck(s, i + 1, j) || PalindromeCheck(s, i, j - 1));
    }

private:
    bool PalindromeCheck(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {return false;}
            start++;
            end--;
        }

        return true;
    }
};
