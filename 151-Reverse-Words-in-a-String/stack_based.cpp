class Solution {
public:
    string reverseWords(string s) {
        string curr = "";
        stack<string> r;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (!curr.empty()) {
                    r.push(curr);
                    curr = "";
                }

                continue;
            }

            curr = curr + s[i];
        }

        string result;

        while (!r.empty()) {
            result = result + r.top();
            result = result + " ";

            r.pop();
        }

        result.pop_back();
        return result;
    }
};
