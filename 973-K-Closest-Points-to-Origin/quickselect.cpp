class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        l = points.size();
        tmp.resize(l);

        for (int i = 0; i < l; i++) {
            result.push_back(i);
            dist.push_back((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
        }

        QuickSelect(points, k, 0, l - 1);

        return r;
    }

private:
    int l;
    vector<int> dist, result, tmp;
    vector<vector<int>> r;

    void QuickSelect(vector<vector<int>>& points, int k, int start, int end) {
        if (start == end) {
            r.push_back(points[result[start]]);
            return;
        }

        int lc = 0, rc = 0;

        for (int i = start + 1; i <= end; i++) {
            if (dist[result[i]] <= dist[result[start]]) {
                tmp[start + lc] = result[i];
                lc++;
            }
            else {
                tmp[end - rc] = result[i];
                rc++;
            }
        }

        if (lc <= k) {
            for (int i = 0; i < lc; i++) {
                r.push_back(points[tmp[start + i]]);
            }

            if (lc < k) {
                r.push_back(points[result[start]]);
            }

            if (lc >= k - 1) {return;}

            for (int i = 0; i < rc; i++) {result[end - i] = tmp[end - i];}
            QuickSelect(points, k - lc - 1, end - rc + 1, end);
            return;
        }

        for (int i = 0; i < lc; i++) {result[start + i] = tmp[start + i];}
        QuickSelect(points, k, start, start + lc - 1);
        return;
    }
};
