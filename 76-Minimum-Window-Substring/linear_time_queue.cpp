class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int start = -1, result = INT_MAX;

        if (m < n) {return "";}

        unordered_map<char, int> hist;

        for (int i = 0; i < n; i++) {hist[t[i]]++;}

        queue<int> pos;
        int count = 0;

        for (int i = 0; i < m; i++) {
            if (hist.find(s[i]) == hist.end()) {continue;}

            if (hist[s[i]] > 0) {count++;}
            hist[s[i]]--;
            pos.push(i);

            if (count == n) {
                while (1) {
                    if (hist[s[pos.front()]] < 0) {
                        hist[s[pos.front()]]++;
                        pos.pop();
                        continue;
                    }
                    break;
                }

                int length = i - pos.front() + 1;

                if (length < result) {
                    result = length;
                    start = pos.front();
                }
            }
        }

        if (start < 0) {return "";}

        return s.substr(start, result);
    }
};
