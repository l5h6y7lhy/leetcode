class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {return false;}
        if (x < 10) {return true;}
        if (x % 10 == 0) {return false;}

        vector<int> r;

        while(x != 0) {
            r.push_back(x % 10);
            x /= 10;
        }

        int i = 0, j = r.size() - 1;

        while(i < j) {
            if (r[i] != r[j]) {return false;}
            i++;
            j--;
        }

        return true;
    }
};
