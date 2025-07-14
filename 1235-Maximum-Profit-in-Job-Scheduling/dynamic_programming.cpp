class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        l = startTime.size();

        for (int i = 0; i < l; i++) {result.push_back(i);}
        for (int i = l / 2; i > 0; i--) {heapifyDown(startTime, i);}

        while(l > 1) {
            result[l - 1] ^= result[0];
            result[0] ^= result[l - 1];
            result[l - 1] ^= result[0];
            l--;
            heapifyDown(startTime, 1);
        }

        l = startTime.size();
        swap();
        nextTime.resize(l, l);

        for (int i = 0; i < l; i++) {
            bSearch(startTime, endTime, i, 0, l - 1);
        }

        vector<int> p(l + 1, 0);
        result.push_back(l);

        for (int i = l - 1; i >= 0; i--) {
            int e = p[nextTime[i]];
            p[i] = max(profit[result[i]] + e, p[i + 1]);
        }

        return p[0];
    }

private:
    int l;
    vector<int> result, nextTime;

    void heapifyDown(vector<int>& nums, int index) {
        int c = nums[result[index - 1]];

        if (index <= (l/2)) {
            int left = nums[result[(2 * index) - 1]];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = nums[result[2 * index]];
            }

            if (left <= right && c > left) {
                result[index - 1] ^= result[(2 * index) - 1];
                result[(2 * index) - 1] ^= result[index - 1];
                result[index - 1] ^= result[(2 * index) - 1];
                heapifyDown(nums, 2 * index);
            }
            else if (left > right && c > right) {
                result[index - 1] ^= result[2 * index];
                result[2 * index] ^= result[index - 1];
                result[index - 1] ^= result[2 * index];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }

    void bSearch(vector<int>& startTime,
                 vector<int>& endTime,
                 int& c, int i1, int i2) {
        if (i1 > i2) {return;}

        int m = (i1 + i2) / 2;
        int index = result[c];

        if (endTime[index] <= startTime[result[m]]) {
            nextTime[c] = m;
            bSearch(startTime, endTime, c, i1, m - 1);
        }
        else {
            bSearch(startTime, endTime, c, m + 1, i2);
        }
    }

    void swap() {
        int i = 0, j = l - 1;

        while (i < j) {
            result[i] ^= result[j];
            result[j] ^= result[i];
            result[i] ^= result[j];

            i++;
            j--;
        }

        return;
    }
};
