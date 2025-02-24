class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (r.size() < k) {
                r.push_back(nums[i]);
                heapifyUp(r.size());
            }
            else if (nums[i] > r[0]) {
                r[0] = nums[i];
                heapifyDown(1);
            }
        }

        t = k;
    }

    int add(int val) {
        if (r.size() < t) {
            r.push_back(val);
            heapifyUp(r.size());
        }
        else if (val > r[0]) {
            r[0] = val;
            heapifyDown(1);
        }

        return r[0];
    }

private:
    int t;
    vector<int> r;

    void heapifyUp(int index) {
        if (index > 1) {
            int parent = index / 2;

            if (r[index - 1] < r[parent - 1]) {
                r[index - 1] ^= r[parent - 1];
                r[parent - 1] ^= r[index - 1];
                r[index - 1] ^= r[parent - 1];
                heapifyUp(parent);
            }
        }
    }

    void heapifyDown(int index) {
        int l = r.size();
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
                heapifyDown(2 * index);
            }
            else if (left > right && c > right) {
                r[index - 1] ^= r[2 * index];
                r[2 * index] ^= r[index - 1];
                r[index - 1] ^= r[2 * index];
                heapifyDown((2 * index) + 1);
            }
        }

        return;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
