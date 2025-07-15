class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int f = 0;
        replace = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == k) {
                f++;
                process();
                continue;
            }

            count[nums[i]]++;
        }

        if (nums.back() != k) {
            process();
        }

        return f + replace;
    }

private:
    int replace;
    unordered_map<int, int> count;

    void process() {
        for (int j = 1; j <= 50; j++) {
            if (count.find(j) != count.end()) {
                if (count[j] > replace) {
                    replace = count[j];
                }

                if (count[j] == 1) {count.erase(j);}
                else {count[j]--;}
            }
        }
    }
};
