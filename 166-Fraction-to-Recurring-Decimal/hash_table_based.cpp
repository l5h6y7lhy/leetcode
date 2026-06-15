class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {

        if (!numerator) {return "0";}

        long n = ((long) numerator);
        long d = ((long) denominator);

        string result = "";

        if (n < 0) {
            n *= (-1);

            if (d > 0) {result = result + '-';}
            else {d *= (-1);}
        }
        else {
            if (d < 0) {
                d *= (-1);
                result = result + '-';
            }
        }

        result = result + to_string(n / d);
        n = n % d;

        if (!n) {return result;}

        result = result + '.';

        vector<int> remainer;
        unordered_map<long, int> pos;

        while (n) {
            n *= 10;

            if (pos.find(n) != pos.end()) {
                int cycle = pos[n];

                for (int i = 0; i < cycle; i++) {
                    result.push_back('0' + remainer[i]);
                }

                result = result + '(';

                for (int i = cycle; i < remainer.size(); i++) {
                    result.push_back('0' + remainer[i]);
                }

                result = result + ')';

                break;
            }

            remainer.push_back(n / d);
            pos[n] = remainer.size() - 1;
            n = n % d;
        }

        if (!n) {
            for (int i = 0; i < remainer.size(); i++) {
                result.push_back('0' + remainer[i]);
            }
        }

        return result;
    }
};
