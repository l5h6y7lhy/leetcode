class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        b_exist = -1;
        e_exist = -1;

        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {b_exist = i;}
            if (wordList[i] == endWord) {e_exist = i;}
            r[wordList[i]] = i;
        }

        if (e_exist < 0) {return 0;}

        if (b_exist < 0) {
            wordList.push_back(beginWord);
            b_exist = wordList.size() - 1;
            r[beginWord] = b_exist;
        }

        int len = 1;
        vector<int> prev, curr;
        prev.push_back(b_exist);

        visited.assign(wordList.size(), false);
        visited[b_exist] = true;

        while (!prev.empty()) {
            for (int p = 0; p < prev.size() && !visited[e_exist]; p++) {
                for (int d = 0; d < beginWord.size() && !visited[e_exist]; d++) {
                    string tmp = wordList[prev[p]];

                    for (int l = 0; l < 26 && !visited[e_exist]; l++) {
                        tmp[d] = 'a' + l;

                        if (r.find(tmp) != r.end() && !visited[r[tmp]]) {
                            visited[r[tmp]] = true;
                            curr.push_back(r[tmp]);
                        }
                    }
                }
            }

            len++;
            if (visited[e_exist]) {break;}

            prev = curr;
            curr.clear();
        }

        if (!visited[e_exist]) {return 0;}

        return len;
    }

private:
    int b_exist, e_exist;
    unordered_map<string, int> r;
    vector<bool> visited;
};
