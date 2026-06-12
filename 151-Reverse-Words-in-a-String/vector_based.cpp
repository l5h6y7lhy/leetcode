class Solution {
public:
    string reverseWords(string s) {
        string curr = "";
        string result = "";

        for (int i = s.size() - 1; i >= -1; i--) {
            if (i == -1 || s[i] == ' ') {
                for (int j = curr.size() - 1; j >= 0; j--) {
                    result = result + curr[j];
                }

                if (!curr.empty()) {result = result + ' ';}

                curr.clear();
                continue;
            }

            curr = curr + s[i];
        }

        result.pop_back();
        return result;
    }
};
