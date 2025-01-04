class Solution {
public:
    int longestValidParentheses(string s) {
        int l = s.size();
        int result = 0;
        int curr = 0;
        int num = 0;
        stack<int> np, len;

        for (int i = 0; i < l; i++) {

            if (s[i] == '(') {
                if (curr) {
                    np.push(num);
                    len.push(curr);
                    num = 0;
                    curr = 0;
                }
                num++;
                continue;
            }

            if (!num) {
                curr = 0;
                continue;
            }

            num--;
            curr += 2;

            while (!num && !np.empty()) {
                num = np.top();
                np.pop();
                curr += len.top();
                len.pop();
            }

            if (curr > result) {result = curr;}
        }

        return result;
    }
};
