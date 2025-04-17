class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        l = points.size();

        for (int i = 0; i < l; i++) {
            result.push_back(i);
            dist.push_back((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
        }

        for (int i = l / 2; i > 0; i--) {heapifyDown(i);}

        while(l > 1) {
            result[l - 1] ^= result[0];
            result[0] ^= result[l - 1];
            result[l - 1] ^= result[0];
            l--;
            heapifyDown(1);
        }

        vector<vector<int>> r;
        l = points.size() - 1;

        for (int i = 0; i < k; i++) {
            r.push_back(points[result[l - i]]);
        }

        return r;
    }

private:
    int l;
    vector<int> dist, result;

    void heapifyDown(int index) {
        int c = dist[result[index - 1]];

        if (index <= (l/2)) {
            int left = dist[result[(2 * index) - 1]];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = dist[result[2 * index]];
            }

            if (left <= right && c > left) {
                result[index - 1] ^= result[(2 * index) - 1];
                result[(2 * index) - 1] ^= result[index - 1];
                result[index - 1] ^= result[(2 * index) - 1];
                heapifyDown(2 * index);
            }
            else if (left > right && c > right) {
                result[index - 1] ^= result[2 * index];
                result[2 * index] ^= result[index - 1];
                result[index - 1] ^= result[2 * index];
                heapifyDown((2 * index) + 1);
            }
        }

        return;
    }
};
