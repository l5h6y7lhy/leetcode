class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        result.assign(nums.size(), 0);
        MergeSort(nums, 0, nums.size() - 1);
        return result;
    }

private:
    vector<int> result;

    vector<int> MergeSort(vector<int>& nums, int s, int e) {
        vector<int> r;

        if (s == e) {
            r.push_back(s);
            return r;
        }

        int m = (s + e) / 2;
        vector<int> left  = MergeSort(nums, s,     m);
        vector<int> right = MergeSort(nums, m + 1, e);

        int i = 0, j = 0;

        while (i < left.size() && j < right.size()) {
            if (nums[right[j]] >= nums[left[i]]) {
                r.push_back(left[i]);
                result[left[i]] += j;
                i++;
            }
            else {
                r.push_back(right[j]);
                j++;
            }
        }

        while (j < right.size()) {
            r.push_back(right[j]);
            j++;
        }

        while (i < left.size()) {
            r.push_back(left[i]);
            result[left[i]] += j;
            i++;
        }

        return r;
    }
};
