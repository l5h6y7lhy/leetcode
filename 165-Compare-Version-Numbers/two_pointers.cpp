class Solution {
public:
    int compareVersion(string version1, string version2) {
        int c1 = 0, c2 = 0;

        while (c1 < version1.size() || c2 < version2.size()) {
            int r1 = current_revision(version1, c1);
            int r2 = current_revision(version2, c2);

            if (r1 < r2) {return -1;}
            if (r1 > r2) {return 1;}
        }

        return 0;
    }

private:
    int current_revision(string& v, int& c) {
        string cv = "";

        while (c < v.size() && v[c] == '0') {
            c++;
        }

        while (c < v.size() && v[c] != '.') {
            cv = cv + v[c];
            c++;
        }

        c++;

        if (cv.empty()) {return 0;}

        return stoi(cv);
    }
};
