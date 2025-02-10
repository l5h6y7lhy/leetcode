class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;

        for (int i = digits.size() - 1; i >= 0 && c; i--) {
            int tmp = digits[i];
            digits[i] = (tmp + c) % 10;
            c = (tmp + c) / 10;
        }

        if (c) {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};
