class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        b_exist = -1;
        e_exist = -1;

        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {b_exist = i;}
            if (wordList[i] == endWord) {e_exist = i;}
            if (b_exist > 0 && e_exist > 0) {break;}
        }

        if (e_exist < 0) {return 0;}

        if (b_exist < 0) {
            wordList.push_back(beginWord);
            b_exist = wordList.size() - 1;
        }

        edge.resize(wordList.size());
        visited.assign(wordList.size(), false);

        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                if (neighborWord(wordList[i], wordList[j])) {
                    edge[i].push_back(j);
                    edge[j].push_back(i);
                }
            }
        }

        int len = 1;
        visited[b_exist] = true;

        vector<int> prev, curr;
        prev.push_back(b_exist);

        while (!prev.empty()) {
            for (int p = 0; p < prev.size() && !visited[e_exist]; p++) {
                for (int i = 0; i < edge[prev[p]].size() && !visited[e_exist]; i++) {
                    int tmp = edge[prev[p]][i];

                    if (!visited[tmp]) {
                        curr.push_back(tmp);
                        visited[tmp] = true;
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
    vector<vector<int>> edge;
    vector<bool> visited;

    bool neighborWord(string& s1, string& s2) {
        int diff = 0;

        for (int i = 0; i < s1.size() && diff < 2; i++) {
            if (s1[i] != s2[i]) {diff++;}
        }

        return (diff == 1);
    }
};
