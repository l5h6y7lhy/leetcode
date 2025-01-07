class Solution {
public:
    int kthFactor(int n, int k) {
        int factor = 1;
        int count = 0;

        while (factor <= n) {
            if (n % factor == 0) {count++;}
            if (count == k) {return factor;}
            factor++;
        }

        return -1;
    }
};
