class Solution {
public:
    string convertToTitle(int columnNumber) {

        string result;

        while(columnNumber) {
            columnNumber--;
            result.push_back('A' + (columnNumber % 26));
            columnNumber = columnNumber / 26;
        }

        int i = 0, j = result.size() - 1;

        while (i < j) {
            char tmp = result[i];
            result[i] = result[j];
            result[j] = tmp;

            i++;
            j--;
        }

        return result;
    }
};
