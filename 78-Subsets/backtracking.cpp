class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        l = nums.size();
        f = -1;
        r.push_back(curr);
        search(nums);
        return r;
    }

private:
    int l, f;
    vector<int> curr;
    vector<vector<int>> r;

    void search(vector<int>& nums) {
        for (int i = f + 1; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            r.push_back(curr);
            f = i;
            search(nums);
            curr.pop_back();
        }
    }
};
