class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {return s;}

        int l = s.size();
        string result;
        result.resize(l);

        int inc = 2 + (2 * (numRows - 2));

        int rp = 0;
        for (int i = 0; i < l; i += inc, rp++) {result[rp] = s[i];}

        for (int nr = 1; nr < numRows - 1; nr++) {
            int i = nr;

            while (i < l) {
                result[rp] = s[i];
                rp++;
                i += 2 * (numRows - 1 - nr);

                if (i >= l) {break;}

                result[rp] = s[i];
                rp++;
                i += 2 * nr;
            }
        }

        for (int i = numRows - 1; i < l; i += inc, rp++) {result[rp] = s[i];}

        return result;
    }
};
