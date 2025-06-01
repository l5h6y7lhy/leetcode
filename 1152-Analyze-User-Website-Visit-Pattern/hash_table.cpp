class Solution {
public:
    struct TupleHash {
        size_t operator()(const tuple<string, string, string>& t) const {
            auto h1 = hash<string>{}(get<0>(t));
            auto h2 = hash<string>{}(get<1>(t));
            auto h3 = hash<string>{}(get<2>(t));

            return h1 ^ (h2 << 1) ^ (h3 << 2);
        }
    };

    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> r;

        for (int i = 0; i < username.size(); i++) {
            pair<int, string> curr(timestamp[i], website[i]);
            r[username[i]].push_back(curr);
        }

        unordered_map<tuple<string, string, string>, int, TupleHash> count;

        for (auto i = r.begin(); i != r.end(); ++i) {
            int t = (i->second).size();
            if (t < 3) {continue;}

            sort((i->second).begin(), (i->second).end());
            unordered_set<tuple<string, string, string>, TupleHash> book;

            for (int a = 0; a < t - 2; a++) {
                for (int b = a + 1; b < t - 1; b++) {
                    if ((i->second)[b].first == (i->second)[a].first) {continue;}

                    for (int c = b + 1; c < t; c++) {
                        if ((i->second)[c].first == (i->second)[b].first) {continue;}

                        tuple<string, string, string> curr((i->second)[a].second,
                                                           (i->second)[b].second,
                                                           (i->second)[c].second);

                        if (book.find(curr) == book.end()) {
                            book.insert(curr);
                            count[curr]++;
                        }
                    }
                }
            }
        }

        int maximum = 0;
        tuple<string, string, string> ct;
        vector<string> result;

        for (auto i = count.begin(); i != count.end(); ++i) {
            if (i->second > maximum ||
                (i->second == maximum && i->first < ct)) {
                    ct = i->first;
                    maximum = i->second;
                }
        }

        result.push_back(get<0>(ct));
        result.push_back(get<1>(ct));
        result.push_back(get<2>(ct));

        return result;
    }
};
