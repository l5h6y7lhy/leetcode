class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, vector<int>> record;

        for(int i=0; i<nums.size(); i++) {record[nums[i]].push_back(i);}

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == target-nums[i] && record[nums[i]].size()>1) {
                result.push_back(record[nums[i]][0]);
                result.push_back(record[nums[i]][1]);
                break;
            }
            else if(nums[i] != target-nums[i] && record.find(target-nums[i]) != record.end()) {
                result.push_back(record[nums[i]][0]);
                result.push_back(record[target-nums[i]][0]);
                break;
            }
        }

        return result;
    }
};
