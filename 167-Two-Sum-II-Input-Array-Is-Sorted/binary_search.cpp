class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        start = 0;
        end = numbers.size() - 1;

        while (result.empty()) {
            binary_search(numbers, target, start + 1);
            start++;
        }

        return result;
    }

private:
    int start, end;
    vector<int> result;

    void binary_search(vector<int>& numbers, int& target, int i) {

        if (i > end) {return;}

        int to_find = target - numbers[start];
        int middle = (i + end) / 2;

        if (numbers[middle] == to_find) {
            result.push_back(start + 1);
            result.push_back(middle + 1);
        }
        else if (numbers[middle] < to_find) {
            binary_search(numbers, target, middle + 1);
        }
        else {
            end = middle - 1;
            binary_search(numbers, target, i);
        }

        return;
    }
};
