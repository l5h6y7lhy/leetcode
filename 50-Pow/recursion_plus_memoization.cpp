class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0.0) {return 0.0;}
        if (x == 1.0) {return 1.0;}
        if (x == -1.0) {
            return (-2.0 * (n % 2)) + 1.0;
        }
        return subPow(x, n);
    }

private:
    unordered_map<int, double> r;

    double subPow(double& x, int n) {
        if (n == 0) {return 1.0;}
        if (n == 1) {return x;}
        if (n == -1) {return 1.0 / x;}
        if (r.find(n) != r.end()) {return r[n];}

        return (r[n] = subPow(x, n / 2) * subPow(x, n - (n / 2)));
    }
};
