class Solution {
public:
    string reverseWords(string s) {

        reverseString(s, 0, s.size() - 1);

        int i = 0, j = 0;

        while (s[j] == ' ') {j++;}

        int state = 1, head = i;

        while (j < s.size()) {
            if (s[j] == ' ' && state == 1) {
                s[i] = s[j];
                i++;
                state = 0;

                reverseString(s, head, i - 2);
            }
            else if (s[j] != ' '){
                s[i] = s[j];
                i++;

                if (state == 0) {
                    state = 1;
                    head = i - 1;
                }
            }

            j++;
        }

        s.resize(i);

        if (s.back() == ' ') {s.pop_back();}
        else {
            reverseString(s, head, i - 1);
        }

        return s;
    }

private:
    void reverseString(string& s, int head, int tail) {

        while (head < tail) {
            char tmp = s[head];
            s[head] = s[tail];
            s[tail] = tmp;

            head++;
            tail--;
        }

        return;
    }
};
