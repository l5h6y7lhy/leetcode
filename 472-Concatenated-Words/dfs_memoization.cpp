class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;

        for (int i = 0; i < words.size(); i++) {
            b.insert(words[i]);
        }

        for (int i = 0; i < words.size(); i++) {
            if (search(words[i], 0) == 2) {result.push_back(words[i]);}
            r.clear();
        }

        return result;
    }

private:
    unordered_set<int> r;
    unordered_set<string> b;

    int search(string& t, int i) {
        if (r.find(i) != r.end()) {return 0;}

        int original = i;
        string curr = "";
        curr += t[i];
        i++;

        while (i < t.size()) {
            if (b.find(curr) != b.end()) {
                int n = search(t, i);

                if (n == 1 || n == 2) {return 2;}
            }

            curr += t[i];
            i++;
        }

        if (b.find(curr) != b.end()) {return 1;}

        r.insert(original);
        return 0;
    }
};
