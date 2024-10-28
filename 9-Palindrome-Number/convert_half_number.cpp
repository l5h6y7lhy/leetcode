class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {return false;}

        int half = 0;

        while(half < x) {
            half = (10 * half) + (x % 10);
            x /= 10;
        }

        return (x == half || x == half/10);
    }
};
