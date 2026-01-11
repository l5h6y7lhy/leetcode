class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> r;

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int second = r.top();
                r.pop();

                int first = r.top();
                r.pop();

                int result;

                if (tokens[i] == "+") {
                    result = first + second;
                }
                else if (tokens[i] == "-") {
                    result = first - second;
                }
                else if (tokens[i] == "*") {
                    result = first * second;
                }
                else {
                    result = first / second;
                }

                r.push(result);
                continue;
            }

            r.push(stoi(tokens[i]));
        }

        return r.top();
    }
};
