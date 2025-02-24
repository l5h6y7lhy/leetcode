class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        count.assign(21, 0);

        for (int i = 0; i < nums.size(); i++) {
            count[nums[i] + 10]++;
        }

        result.push_back(curr);
        search(0);
        return result;
    }

private:
    vector<int> count;
    vector<int> curr;
    vector<vector<int>> result;

    void search(int s) {
        for (int i = s; i < 21; i++) {
            if (!count[i]) {continue;}

            for (int j = 0; j < count[i]; j++) {
                curr.push_back(i - 10);
                result.push_back(curr);
                search(i + 1);
            }

            for (int j = 0; j < count[i]; j++) {curr.pop_back();}
        }
    }
};
