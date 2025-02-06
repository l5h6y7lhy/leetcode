class Solution {
public:
    string getPermutation(int n, int k) {
        int i, f = 1;
        k--;
        string result = "";

        vector<bool> book(n, false);

        for (i = 2; i < n; i++) {f *= i;}

        i = n;

        while (1) {
            int t = k / f;
            int c = -1;

            for (int j = 0; j < n; j++) {
                if (!book[j]) {c++;}

                if (c == t) {
                    book[j] = true;
                    result.push_back('1' + j);
                    break;
                }
            }

            i--;
            k = k % f;

            if (!i) {break;}
            f /= i;
        }

        return result;
    }
};
