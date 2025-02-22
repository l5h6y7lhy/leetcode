class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        int start = -1, result = INT_MAX;
        int head = 0;

        if (m < n) {return "";}

        unordered_map<char, int> hist;

        for (int i = 0; i < n; i++) {hist[t[i]]++;}

        int count = 0;

        for (int i = 0; i < m; i++) {
            if (hist.find(s[i]) == hist.end()) {continue;}

            if (hist[s[i]] > 0) {count++;}
            hist[s[i]]--;

            if (count == n) {
                while (1) {
                    if (hist.find(s[head]) == hist.end()) {
                        head++;
                        continue;
                    }

                    if (hist[s[head]] < 0) {
                        hist[s[head]]++;
                        head++;
                        continue;
                    }

                    break;
                }

                int length = i - head + 1;

                if (length < result) {
                    result = length;
                    start = head;
                }
            }
        }

        if (start < 0) {return "";}

        return s.substr(start, result);
    }
};
