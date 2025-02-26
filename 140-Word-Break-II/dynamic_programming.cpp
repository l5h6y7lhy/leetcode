class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        l = s.size();
        unordered_map<string, int> r;
        for (int i = 0; i < wordDict.size(); i++) {r[wordDict[i]] = i;}

        b.resize(l + 1);
        b[l].push_back(-1);

        for (int j = l - 1; j >= 0; j--) {
            int len = (s.size() - j > 10) ? 10 : s.size() - j;
            string tmp = s.substr(j, len);

            while (!tmp.empty()) {
                if (r.find(tmp) != r.end() && !b[j + len].empty()) {
                    b[j].push_back(r[tmp]);
                }
                len--;
                tmp.pop_back();
            }
        }

        search(0, wordDict);

        return result;
    }

private:
    int l;
    vector<vector<int>> b;
    vector<int> curr;
    vector<string> result;

    void search(int p, vector<string>& wordDict) {
        if (p == l) {
            string c;

            for (int i = 0; i < curr.size(); i++) {
                c = c + wordDict[curr[i]] + " ";
            }

            c.pop_back();
            result.push_back(c);
            return;
        }

        for (int i = 0; i < b[p].size(); i++) {
            curr.push_back(b[p][i]);
            search(p + wordDict[b[p][i]].size(), wordDict);
            curr.pop_back();
        }

        return;
    }
};
