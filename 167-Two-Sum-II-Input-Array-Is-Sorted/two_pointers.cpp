class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        vector<int> result(2);

        int i = 0, j = numbers.size() - 1;

        while (1) {
            int curr = numbers[i] + numbers[j];

            if (curr > target) {j--;}
            else if (curr < target) {i++;}
            else {
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            }
        }

        return result;
    }
};
