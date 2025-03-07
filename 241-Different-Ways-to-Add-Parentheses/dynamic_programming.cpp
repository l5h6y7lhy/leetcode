class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        string num = "";
        vector<int> nums;

        for (int i = 0; i < expression.size(); i++) {
            if (expression[i] >= '0' && expression[i] <= '9') {
                num += expression[i];
            }
            else {
                nums.push_back(stoi(num));
                num = "";
                operators.push_back(expression[i]);
            }
        }

        nums.push_back(stoi(num));
        result.resize(nums.size());

        for (int i = 0; i < nums.size(); i++) {result[i].resize(nums.size());}
        for (int i = 0; i < nums.size(); i++) {result[i][i].push_back(nums[i]);}

        for (int l = 1; l < nums.size(); l++) {
            for (int i = 0; i < nums.size() - l; i++) {
                carry(i, i + l);
            }
        }

        return result[0][nums.size() - 1];
    }

private:
    vector<char> operators;
    vector<vector<vector<int>>> result;

    void carry(int start, int end) {
        for (int j = start; j < end; j++) {
            for (int m = 0; m < result[start][j].size(); m++) {
                for (int n = 0; n < result[j + 1][end].size(); n++) {
                    int tmp;

                    if (operators[j] == '+') {
                        tmp = result[start][j][m] + result[j + 1][end][n];
                    }
                    else if (operators[j] == '-') {
                        tmp = result[start][j][m] - result[j + 1][end][n];
                    }
                    else {
                        tmp = result[start][j][m] * result[j + 1][end][n];
                    }

                    result[start][end].push_back(tmp);
                }
            }
        }
    }
};
