class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        int l = s.size();
        lower.resize(l);

        for (int i = 0; i < l; i++) {
            lower[i].assign(l, -1);
        }

        return check(s, k, 0, l - 1);
    }

private:
    vector<vector<int>> lower;

    bool check(string& s, int k, int start, int end) {
        if (k <= lower[start][end]) {return false;}
        if (k >= end - start - 1) {return true;}

        while (start < end) {
            if (s[start] != s[end]) {break;}
            start++;
            end--;
        }

        if (start >= end ||
            check(s, k - 1, start + 1, end) ||
            check(s, k - 1, start, end - 1)) {
            return true;
        }

        lower[start][end] = k;
        return false;
    }
};
