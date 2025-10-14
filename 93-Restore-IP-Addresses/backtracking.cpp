class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        search(s, 0, 0);
        return r;
    }

private:
    string curr;
    vector<string> r;

    void search(string& s, int index, int c) {
        if (c == 4) {
            if (index == s.size()) {
                curr.pop_back();
                r.push_back(curr);
                curr += '.';
            }

            return;
        }

        if (index == s.size()) {return;}

        string num = "";

        for (int i = index; i < s.size(); i++) {
            num += s[i];
            curr += s[i];

            if (stoi(num) > 255) {break;}

            curr += '.';
            search(s, i + 1, c + 1);
            curr.pop_back();

            if (num == "0") {break;}
        }

        for (int i = 0; i < num.size(); i++) {
            curr.pop_back();
        }
    }
};
