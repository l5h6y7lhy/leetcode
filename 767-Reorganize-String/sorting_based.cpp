class Solution {
public:
    string reorganizeString(string s) {
        if (s.size() < 2) {return s;}

        unordered_map<char, int> r;
        for (int i = 0; i < s.size(); i++) {r[s[i]]++;}

        for (int i = 0; i < 26; i++) {
            char c = 'a' + i;

            if (r[c]) {
                q.push_back(pair(r[c], c));
            }
        }

        if (q.size() < 2) {return "";}

        sort(q.begin(), q.end());

        int i1 = 0, i2 = q.size() - 1;

        while (i1 < i2) {
            pair<int, char> tmp = q[i1];
            q[i1] = q[i2];
            q[i2] = tmp;
            i1++;
            i2--;
        }

        if (q[0].first == q[1].first) {uniform();}
        else {sum();}

        return result;
    }

private:
    vector<pair<int, char>> q;
    string result;

    void uniform() {
        while (q[0].first) {
            for (int i = 0; i < q.size(); i++) {
                if (q[i].first) {
                    result += q[i].second;
                    q[i].first--;
                }
            }
        }

        return;
    }

    void sum() {
        int target = (--q[0].first);
        int pivot;

        for (int i = 1; i < q.size(); i++) {
            if (target > q[i].first) {target -= q[i].first;}
            else {
                q[i].first -= target;
                target = 0;
            }

            if (target == 0) {
                pivot = i;
                break;
            }
        }

        if (target > 0) {
            result = "";
            return;
        }

        int s1 = 1;

        for (int i = 0; i < q[0].first; i++) {
            result += q[0].second;

            if (s1 < pivot) {
                result += q[s1].second;
                q[s1].first--;
                if (!q[s1].first) {s1++;}
            }
            else {result += q[s1].second;}

            for (int i = pivot; i < q.size(); i++) {
                if (q[i].first) {
                    result += q[i].second;
                    q[i].first--;
                }
            }
        }

        result += q[0].second;
    }
};
