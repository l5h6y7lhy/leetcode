class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {return s;}

        vector<string> r;
        r.resize(numRows);

        c = 0;
        l = s.size();
        down = true;

        for(int i = 0; i < l; i++) {
            r[c].push_back(s[i]);
            nextStep(numRows);
        }

        string result = r[0];

        for(int i = 1; i < numRows; i++) {result = result + r[i];}

        return result;
    }

private:
    int c;
    int l;
    bool down;

    int step() {
        if (down) {return 1;}
        return -1;
    }

    void nextStep(int& nR) {
        if (down && c < nR -1) {c += step();}
        else if (!down && c > 0) {c += step();}
        else {
            c -= step();
            down = !down;
        }
    }
};
