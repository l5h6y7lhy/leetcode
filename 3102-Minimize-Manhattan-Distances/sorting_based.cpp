class Solution {
public:
    int minimumDistance(vector<vector<int>>& points) {
        int l = points.size();
        vector<int> tmp(2);
        vector<vector<int>> up, down;

        for (int i = 0; i < l; i++) {
            tmp[1] = i;

            tmp[0] = points[i][0] + points[i][1];
            up.push_back(tmp);

            tmp[0] = points[i][0] - points[i][1];
            down.push_back(tmp);
        }

        sort(up.begin(), up.end());
        sort(down.begin(), down.end());

        int s1 = up[l - 1][0] - up[0][0];
        int s2 = down[l - 1][0] - down[0][0];

        vector<vector<int>>& large = (s1 >= s2) ? up : down;
        vector<vector<int>>& small = (s1 >= s2) ? down : up;

        s1 = large[l - 1][0] - large[1][0];
        int p1 = 0, p2 = l - 1;
        if (small[p1][1] == large[0][1]) {p1++;}
        if (small[p2][1] == large[0][1]) {p2--;}
        s2 = small[p2][0] - small[p1][0];
        int r1 = max(s1, s2);

        s1 = large[l - 2][0] - large[0][0];
        p1 = 0;
        p2 = l - 1;
        if (small[p1][1] == large[l - 1][1]) {p1++;}
        if (small[p2][1] == large[l - 1][1]) {p2--;}
        s2 = small[p2][0] - small[p1][0];
        int r2 = max(s1, s2);

        return min(r1, r2);
    }
};
