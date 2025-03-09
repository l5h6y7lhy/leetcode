class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        result.assign(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {reo.push_back(i);}
        tmp.resize(nums.size());

        MergeSort(nums, 0, nums.size() - 1);
        return result;
    }

private:
    vector<int> result, reo, tmp;

    void MergeSort(vector<int>& nums, int s, int e) {
        if (s == e) {
            return;
        }

        int m = (s + e) / 2;
        MergeSort(nums, s,     m);
        MergeSort(nums, m + 1, e);

        int i = 0, j = 0;

        while (i < m - s + 1 && j < e - m) {
            if (nums[reo[m + 1 + j]] >= nums[reo[s + i]]) {
                tmp[s + i + j] = reo[s + i];
                result[reo[s + i]] += j;
                i++;
            }
            else {
                tmp[s + i + j] = reo[m + 1 + j];
                j++;
            }
        }

        while (j < e - m) {
            tmp[s + i + j] = reo[m + 1 + j];
            j++;
        }

        while (i < m - s + 1) {
            tmp[s + i + j] = reo[s + i];
            result[reo[s + i]] += j;
            i++;
        }

        for (int l = s; l <= e; l++) {reo[l] = tmp[l];}

        return;
    }
};
