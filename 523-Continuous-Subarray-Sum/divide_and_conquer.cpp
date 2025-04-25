class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        return search(nums, k, 0, nums.size() - 1);
    }

private:
    bool search(vector<int>& nums, int& k, int start, int end) {
        if (start == end) {
            return false;
        }

        int middle = (start + end) / 2;

        if (search(nums, k, start, middle)) {return true;}
        if (search(nums, k, middle + 1, end)) {return true;}

        int total = 0;
        unordered_set<int> r;

        for (int i = middle; i >= start; i--) {
            total += nums[i];
            r.insert(total % k);
        }

        total = 0;

        for (int i = middle + 1; i <= end; i++) {
            total += nums[i];
            int tmp = total % k;

            if (!tmp && r.find(tmp) != r.end()) {return true;}
            else if (r.find(k - tmp) != r.end()) {return true;}
        }

        return false;
    }
};
