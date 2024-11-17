class Solution {
public:
    vector<string> letterCombinations(string digits) {
        l = digits.size();
        if (!l) {return result;}

        code = {
            {'a', 'b', 'c'},
            {'d', 'e', 'f'},
            {'g', 'h', 'i'},
            {'j', 'k', 'l'},
            {'m', 'n', 'o'},
            {'p', 'q', 'r', 's'},
            {'t', 'u', 'v'},
            {'w', 'x', 'y', 'z'}
        };

        addChar(0, digits);

        return result;
    }

private:
    int l;
    vector<string> result;
    string curr;
    vector<vector<char>> code;

    void addChar(int p, string& digits) {
        if (p == l) {
            result.push_back(curr);
            return;
        }

        int index = digits[p] - '2';

        for (int i = 0; i < code[index].size(); i++) {
            curr.push_back(code[index][i]);
            addChar(p + 1, digits);
            curr.pop_back();
        }

        return;
    }
};
