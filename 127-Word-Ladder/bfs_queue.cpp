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

        queue<int> prev;
        prev.push(b_exist);

        visited.assign(wordList.size(), 0);
        visited[b_exist] = 1;

        while (!prev.empty()) {
            for (int d = 0; d < beginWord.size() && !visited[e_exist]; d++) {
                string tmp = wordList[prev.front()];
                int cl = visited[prev.front()] + 1;

                for (int l = 0; l < 26 && !visited[e_exist]; l++) {
                    tmp[d] = 'a' + l;

                    if (r.find(tmp) != r.end() && !visited[r[tmp]]) {
                        visited[r[tmp]] = cl;
                        prev.push(r[tmp]);
                    }
                }
            }

            if (visited[e_exist]) {break;}

            prev.pop();
        }

        if (!visited[e_exist]) {return 0;}

        return visited[e_exist];
    }

private:
    int b_exist, e_exist;
    unordered_map<string, int> r;
    vector<int> visited;
};
