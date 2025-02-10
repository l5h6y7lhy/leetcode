class Solution {
public:
    string addBinary(string a, string b) {
        int c = 0;
        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;

        while (i >= 0 || j >= 0) {
            int numa = ((i--) >= 0) ? a[i + 1] - '0' : 0;
            int numb = ((j--) >= 0) ? b[j + 1] - '0' : 0;
            c = numa + numb + c;
            result.push_back('0' + (c % 2));
            c = c / 2;
        }

        if (c) {result.push_back('1');}

        i = 0;
        j = result.size() - 1;

        while (i < j) {
            result[i] ^= result[j];
            result[j] ^= result[i];
            result[i] ^= result[j];
            i++;
            j--;
        }

        return result;
    }
};
