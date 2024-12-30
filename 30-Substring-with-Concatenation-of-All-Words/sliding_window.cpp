class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int sl = s.size();
        int wl = words.size();
        int ws = words[0].size();
        vector<int> result;

        if (wl * ws > sl) {return result;}

        unordered_map<string, int> r;

        for (int i = 0; i < wl; i++) {
            r[words[i]]++;
        }

        vector<string> book;
        book.resize(sl - ws + 1);

        for (int i = 0; i < sl - ws + 1; i++) {
            book[i] = s.substr(i, ws);
        }

        for (int i = 0; i < ws; i++) {

            int l1 = i;
            int l2 = i;

            while (1) {

                if (l2 + ws > sl) {
                    while (l1 < l2) {
                        r[book[l1]]++;
                        l1 += ws;
                    }
                    break;
                }

                if (r.find(book[l2]) == r.end()) {
                    while (l1 < l2) {
                        r[book[l1]]++;
                        l1 += ws;
                    }

                    l1 += ws;
                    l2 += ws;
                    continue;
                }

                r[book[l2]]--;
                while (r[book[l2]] < 0) {
                    r[book[l1]]++;
                    l1 += ws;
                }

                l2 += ws;

                if ((l2 - l1) / ws == wl) {
                    result.push_back(l1);
                    r[book[l1]]++;
                    l1 += ws;
                }
            }
        }

        return result;
    }
};
