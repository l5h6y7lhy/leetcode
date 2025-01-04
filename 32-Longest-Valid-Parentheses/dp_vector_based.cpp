class Solution {
public:
    int longestValidParentheses(string s) {
        l = s.size();
        result = 0;
        curr = 0;
        r.push_back(-2);

        while (curr < l - 1) {
            search(s);
        }

        return result;
    }

private:
    int l;
    int result;
    int curr;
    vector<int> r;

    void search(string& s) {
        int start = curr;
        int end = curr + 1;

        while (1) {
            while (start >= 0 && end < l) {
                if (s[start] == ')' || s[end] == '(') {break;}
                start--;
                end++;
            }

            if (start == r.back()) {
                r.pop_back();
                start = r.back() - 1;
                r.pop_back();
                continue;
            }

            if (end - start - 1 > 0) {
                r.push_back(start + 1);
                r.push_back(end - 1);
            }

            if (end - start - 1 > result) {
                result = end - start - 1;
            }

            curr = end;
            break;
        }

        return;
    }
};
