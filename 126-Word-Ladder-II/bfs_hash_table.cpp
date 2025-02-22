class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        b_exist = -1;
        e_exist = -1;

        for (int i = 0; i < wordList.size(); i++) {
            if (wordList[i] == beginWord) {b_exist = i;}
            if (wordList[i] == endWord) {e_exist = i;}
            r[wordList[i]] = i;
        }

        if (e_exist < 0) {return t_path;}

        if (b_exist < 0) {
            wordList.push_back(beginWord);
            b_exist = wordList.size() - 1;
            r[beginWord] = b_exist;
        }

        vector<int> prev, curr;
        prev.push_back(e_exist);

        visited.assign(wordList.size(), 0);
        visited[e_exist] = 1;

        parent.resize(wordList.size());
        parent[e_exist].push_back(-1);

        while (1) {
            for (int p = 0; p < prev.size(); p++) {
                for (int d = 0; d < beginWord.size(); d++) {
                    string tmp = wordList[prev[p]];

                    for (int l = 0; l < 26; l++) {
                        tmp[d] = 'a' + l;

                        if (r.find(tmp) != r.end() && visited[r[tmp]] != 1) {
                            if (!visited[r[tmp]]) {curr.push_back(r[tmp]);}
                            visited[r[tmp]] = 2;
                            parent[r[tmp]].push_back(prev[p]);
                        }
                    }
                }
            }

            prev = curr;
            curr.clear();

            for (int i = 0; i < prev.size(); i++) {visited[prev[i]] = 1;}
            if (visited[b_exist] == 1) {break;}
            if (prev.empty()) {break;}
        }

        addPath(wordList, b_exist);

        return t_path;
    }

private:
    int b_exist, e_exist;
    unordered_map<string, int> r;
    vector<int> visited;
    vector<vector<int>> parent;
    vector<string> path;
    vector<vector<string>> t_path;

    void addPath(vector<string>& wordList, int index) {
        if (index < 0) {
            t_path.push_back(path);
            return;
        }

        path.push_back(wordList[index]);

        for (int i = 0; i < parent[index].size(); i++) {
            addPath(wordList, parent[index][i]);
        }

        path.pop_back();
        return;
    }
};
