class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        t = k;

        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }

    int add(int val) {
        if (r.size() < t) {
            r.push(val * (-1));
        }
        else {
            int c = r.top() * (-1);

            if (val > c) {
                r.pop();
                r.push(val * (-1));
            }
        }

        return r.top() * (-1);
    }

private:
    int t;
    priority_queue<int> r;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
