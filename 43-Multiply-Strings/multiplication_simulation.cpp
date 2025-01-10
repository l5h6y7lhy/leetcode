class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();

        int curr = 0, tc = 0;
        string result = "";

        vector<vector<int>> r;
        r.resize(l1 + 1);

        for (int i = l2 - 1; i >= 0; i--) {
            int c2 = num2[i] - '0';
            int carry = 0;

            for (int j = l1 - 1; j >= 0; j--) {
                int p = (c2 * (num1[j] - '0')) + carry;
                r[curr].push_back(p % 10);
                carry = p / 10;
            }

            if (carry) {r[curr].push_back(carry);}

            for (int j = 0; j < l1 + 1; j++) {
                int index = (curr - j + l1 + 1) % (l1 + 1);
                if (r[index].size() >= j + 1) {tc += r[index][j];}
            }

            result += ('0' + (tc % 10));
            tc /= 10;

            curr = (curr + 1) % (l1 + 1);
            r[curr].resize(0);
        }

        for (int i = 1; i < l1 + 1; i ++) {
            curr = (curr + 1) % (l1 + 1);

            for (int j = 0; j < (l1 + 1 - i); j++) {
                int index = (curr + j) % (l1 + 1);
                if (r[index].size() >= l1 - j + 1) {tc += r[index][l1 - j];}
            }

            result += ('0' + (tc % 10));
            tc /= 10;
        }

        if (tc) {result += ('0' + tc);}

        while (result.size() > 1 && result.back() == '0') {
            result.resize(result.size() - 1);
        }

        int i = 0, j = result.size() - 1;

        while (i < j){
            char ca = result[i];
            result[i] = result[j];
            result[j] = ca;
            i++; j--;
        }

        return result;
    }
};
