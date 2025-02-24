class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        f = 1;
        key = 0;

        for (int i = 0; i < 10; i++) {
            key *= 4;
            f *= 4;

            if (s[i] == 'A') {key += 0;}
            else if (s[i] == 'C') {key += 1;}
            else if (s[i] == 'G') {key += 2;}
            else {key += 3;}
        }

        vector<int> r(f, 0);
        r[key] = 1;
        f /= 4;

        for (int i = 10; i < s.size(); i++) {
            key = key % f;
            key *= 4;

            if (s[i] == 'A') {key += 0;}
            else if (s[i] == 'C') {key += 1;}
            else if (s[i] == 'G') {key += 2;}
            else {key += 3;}

            r[key]++;

            if (r[key] == 2) {addSeq();}
        }

        return result;
    }

private:
    int f;
    int key;
    vector<string> result;
    char dic[4] = {'A', 'C', 'G', 'T'};

    void addSeq() {
        int k = key;
        int c = f;

        string curr;

        while (c) {
            curr.push_back(dic[k / c]);
            k = k % c;
            c = c / 4;
        }

        result.push_back(curr);
        return;
    }
};
