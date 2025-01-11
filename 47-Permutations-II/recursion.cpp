class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        l = nums.size();
        count = 0;
        book.resize(l);

        search(nums);
        return result;
    }

private:
    int l, count;
    vector<int> curr;
    vector<bool> book;
    vector<vector<int>> result;

    void search(vector<int>& nums) {
        if (count == l) {
            result.push_back(curr);
        }

        vector<bool> r;
        r.resize(21);
        count++;

        for (int i = 0; i < l; i++) {
            if (!book[i] && !r[nums[i] + 10]) {
                r[nums[i] + 10] = true;
                book[i] = true;
                curr.push_back(nums[i]);
                search(nums);
                curr.pop_back();
                book[i] = false;
            }
        }

        count--;
        return;
    }
};
