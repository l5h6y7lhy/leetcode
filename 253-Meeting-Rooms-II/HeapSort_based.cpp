class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> r1, r2;
        l = intervals.size();

        for (int i = 0; i < l; i++) {
            r1.push_back(intervals[i][0]);
            r2.push_back(intervals[i][1]);
        }

        for (int i = l / 2; i > 0; i--) {
            heapifyDown(i, r1);
            heapifyDown(i, r2);
        }

        while(l > 1) {
            r1[l - 1] ^= r1[0];
            r1[0] ^= r1[l - 1];
            r1[l - 1] ^= r1[0];

            r2[l - 1] ^= r2[0];
            r2[0] ^= r2[l - 1];
            r2[l - 1] ^= r2[0];

            l--;
            heapifyDown(1, r1);
            heapifyDown(1, r2);
        }

        l = intervals.size() - 1;
        int h = l;
        int count = 0;
        int result = 0;

        while (1) {
            if (r1[l] < r2[h]) {
                count++;
                l--;
            }
            else if (r1[l] == r2[h]) {
                l--;
                h--;
            }
            else {
                count--;
                h--;
            }

            if (count > result) {result = count;}
            if (l < 0) {break;}
        }

        return result;
    }

private:
    int l;

    void heapifyDown(int index, vector<int>& r) {
        int c = r[index - 1];

        if (index <= (l/2)) {
            int left = r[(2 * index) - 1];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = r[2 * index];
            }

            if (left <= right && c > left) {
                r[index - 1] ^= r[(2 * index) - 1];
                r[(2 * index) - 1] ^= r[index - 1];
                r[index - 1] ^= r[(2 * index) - 1];
                heapifyDown(2 * index, r);
            }
            else if (left > right && c > right) {
                r[index - 1] ^= r[2 * index];
                r[2 * index] ^= r[index - 1];
                r[index - 1] ^= r[2 * index];
                heapifyDown((2 * index) + 1, r);
            }
        }

        return;
    }
};
