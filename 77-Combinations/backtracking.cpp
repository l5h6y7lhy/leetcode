class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        add(n, k, 1);
        return result;
    }

private:
    vector<int> tmp;
    vector<vector<int>> result;

    void add(int& n, int& k, int curr) {
        if (!k) {
            result.push_back(tmp);
            return;
        }

        if (curr > n) {return;}

        k--;

        for (int i = curr; i <= n; i++) {
            tmp.push_back(i);
            add(n, k, i + 1);
            tmp.pop_back();
        }

        k++;

        return;
    }
};