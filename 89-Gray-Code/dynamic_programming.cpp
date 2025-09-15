class Solution {
public:
    vector<int> grayCode(int n) {
        int t = 2;
        vector<int> result;
        result.push_back(0);
        result.push_back(1);

        for (int i = 2; i <= n; i++) {
            int l = result.size();

            for (int j = l - 1; j >= 0; j--) {
                result.push_back(result[j] + t);
            }

            t *= 2;
        }

        return result;
    }
};