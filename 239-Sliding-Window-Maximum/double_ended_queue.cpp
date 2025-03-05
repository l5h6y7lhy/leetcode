class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {return nums;}

        deque<int> q;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            while (!q.empty() && i - q.front() > k - 1) {q.pop_front();}

            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }

        return result;
    }
};
