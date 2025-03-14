class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        l = intervals.size();

        for (int i = 0; i < l; i++) {
            r1.push_back(intervals[i][0]);
            r2.push_back(intervals[i][1]);
        }

        for (int i = l / 2; i > 0; i--) {
            heapifyDownr1(i);
            heapifyDownr2(i);
        }

        while(l > 1) {
            r1[l - 1] ^= r1[0];
            r1[0] ^= r1[l - 1];
            r1[l - 1] ^= r1[0];

            r2[l - 1] ^= r2[0];
            r2[0] ^= r2[l - 1];
            r2[l - 1] ^= r2[0];

            l--;
            heapifyDownr1(1);
            heapifyDownr2(1);
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
    vector<int> r1, r2;

    void heapifyDownr1(int index) {
        int c = r1[index - 1];

        if (index <= (l/2)) {
            int left = r1[(2 * index) - 1];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = r1[2 * index];
            }

            if (left <= right && c > left) {
                r1[index - 1] ^= r1[(2 * index) - 1];
                r1[(2 * index) - 1] ^= r1[index - 1];
                r1[index - 1] ^= r1[(2 * index) - 1];
                heapifyDownr1(2 * index);
            }
            else if (left > right && c > right) {
                r1[index - 1] ^= r1[2 * index];
                r1[2 * index] ^= r1[index - 1];
                r1[index - 1] ^= r1[2 * index];
                heapifyDownr1((2 * index) + 1);
            }
        }

        return;
    }

    void heapifyDownr2(int index) {
        int c = r2[index - 1];

        if (index <= (l/2)) {
            int left = r2[(2 * index) - 1];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = r2[2 * index];
            }

            if (left <= right && c > left) {
                r2[index - 1] ^= r2[(2 * index) - 1];
                r2[(2 * index) - 1] ^= r2[index - 1];
                r2[index - 1] ^= r2[(2 * index) - 1];
                heapifyDownr2(2 * index);
            }
            else if (left > right && c > right) {
                r2[index - 1] ^= r2[2 * index];
                r2[2 * index] ^= r2[index - 1];
                r2[index - 1] ^= r2[2 * index];
                heapifyDownr2((2 * index) + 1);
            }
        }

        return;
    }
};
