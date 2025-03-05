class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        l = intervals.size();

        for (int i = 0; i < l; i++) {
            r1.push_back(i);
            r2.push_back(i);
        }

        for (int i = l / 2; i > 0; i--) {
            heapifyDownr1(intervals, i);
            heapifyDownr2(intervals, i);
        }

        while(l > 1) {
            r1[l - 1] ^= r1[0];
            r1[0] ^= r1[l - 1];
            r1[l - 1] ^= r1[0];

            r2[l - 1] ^= r2[0];
            r2[0] ^= r2[l - 1];
            r2[l - 1] ^= r2[0];

            l--;
            heapifyDownr1(intervals, 1);
            heapifyDownr2(intervals, 1);
        }

        l = intervals.size() - 1;
        int h = l;
        int count = 0;
        int result = 0;

        while (1) {
            if (intervals[r1[l]][0] < intervals[r2[h]][1]) {
                count++;
                l--;
            }
            else if (intervals[r1[l]][0] == intervals[r2[h]][1]) {
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
    vector<int> r1, r2;

    void heapifyDownr1(vector<vector<int>>& intervals, int index) {
        int c = intervals[r1[index - 1]][0];

        if (index <= (l/2)) {
            int left = intervals[r1[(2 * index) - 1]][0];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = intervals[r1[2 * index]][0];
            }

            if (left <= right && c > left) {
                r1[index - 1] ^= r1[(2 * index) - 1];
                r1[(2 * index) - 1] ^= r1[index - 1];
                r1[index - 1] ^= r1[(2 * index) - 1];
                heapifyDownr1(intervals, 2 * index);
            }
            else if (left > right && c > right) {
                r1[index - 1] ^= r1[2 * index];
                r1[2 * index] ^= r1[index - 1];
                r1[index - 1] ^= r1[2 * index];
                heapifyDownr1(intervals, (2 * index) + 1);
            }
        }

        return;
    }

    void heapifyDownr2(vector<vector<int>>& intervals, int index) {
        int c = intervals[r2[index - 1]][1];

        if (index <= (l/2)) {
            int left = intervals[r2[(2 * index) - 1]][1];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = intervals[r2[2 * index]][1];
            }

            if (left <= right && c > left) {
                r2[index - 1] ^= r2[(2 * index) - 1];
                r2[(2 * index) - 1] ^= r2[index - 1];
                r2[index - 1] ^= r2[(2 * index) - 1];
                heapifyDownr2(intervals, 2 * index);
            }
            else if (left > right && c > right) {
                r2[index - 1] ^= r2[2 * index];
                r2[2 * index] ^= r2[index - 1];
                r2[index - 1] ^= r2[2 * index];
                heapifyDownr2(intervals, (2 * index) + 1);
            }
        }

        return;
    }
};
