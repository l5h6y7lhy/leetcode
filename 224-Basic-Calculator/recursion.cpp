class Solution {
public:
    int calculate(string s) {
        i = 0;
        return analyze(s);
    }

private:
    int i;

    int analyze(string& s) {
        int curr;
        char operation = '*';

        while (i < s.size()) {
            int tmp;

            if (s[i] == '-') {
                curr = 0;
                operation = s[i];
                i++;
                continue;
            }
            else if (s[i] == ' ') {
                i++;
                continue;
            }
            else if (s[i] == '(') {
                i++;
                tmp = analyze(s);

                while (s[i] == ' ') {i++;}
            }
            else {
                string t;

                while (i < s.size()) {
                    if (s[i] == ' ') {
                        i++;
                        continue;
                    }
                    else if (s[i] >= '0' && s[i] <= '9') {
                        t.push_back(s[i]);
                        i++;
                    }
                    else {break;}
                }

                tmp = stoi(t);
            }

            if (operation == '*') {curr = tmp;}
            else if (operation == '+') {curr += tmp;}
            else {curr -= tmp;}

            if (i >= s.size() || s[i] == ')') {
                i++;
                break;
            }

            operation = s[i];
            i++;
        }

        return curr;
    }
};
