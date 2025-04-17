class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> r;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {r.push(i);}
            else if (s[i] == ')' && !r.empty()) {
                s[r.top()] = '0';
                s[i] = '1';
                r.pop();
            }
        }

        string result;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {result += '(';}
            else if (s[i] == '1') {result += ')';}
            else if (s[i] >= 'a' && s[i] <= 'z') {result += s[i];}
        }

        return result;
    }
};
