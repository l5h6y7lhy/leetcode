class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        return merge(buildings, 0, buildings.size() - 1);
    }

private:
    vector<vector<int>> merge(vector<vector<int>>& buildings, int l, int r) {
        vector<int> tmp(2);
        vector<vector<int>> result;

        if (l == r) {
            tmp[0] = buildings[l][0];
            tmp[1] = buildings[l][2];
            result.push_back(tmp);

            tmp[0] = buildings[l][1];
            tmp[1] = 0;
            result.push_back(tmp);

            return result;
        }

        int m = (l + r) / 2;

        vector<vector<int>> r1 = merge(buildings, l,     m);
        vector<vector<int>> r2 = merge(buildings, m + 1, r);

        int pos, prevh = 0;
        int i1 = 0, i2 = 0;
        int h1 = 0, h2 = 0;

        while (i1 < r1.size() || i2 < r2.size()) {
            if (i1 == r1.size()) {
                h2 = r2[i2][1];
                pos = r2[i2][0];
                i2++;
            }
            else if (i2 == r2.size()) {
                h1 = r1[i1][1];
                pos = r1[i1][0];
                i1++;
            }
            else if (r1[i1][0] < r2[i2][0]) {
                h1 = r1[i1][1];
                pos = r1[i1][0];
                i1++;
            }
            else if (r1[i1][0] > r2[i2][0]) {
                h2 = r2[i2][1];
                pos = r2[i2][0];
                i2++;
            }
            else {
                pos = r1[i1][0];

                h1 = r1[i1][1];
                i1++;

                h2 = r2[i2][1];
                i2++;
            }

            int currh = max(h1, h2);

            if (currh != prevh) {
                tmp[0] = pos;
                tmp[1] = currh;
                result.push_back(tmp);
                prevh = currh;
            }
        }

        return result;
    }
};
