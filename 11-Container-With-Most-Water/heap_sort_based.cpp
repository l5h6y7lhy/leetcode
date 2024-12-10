class Solution {
public:
    int maxArea(vector<int>& height) {
        l = height.size();

        for (int i = 0; i < l; i++) {result.push_back(i);}
        for (int i = l / 2; i > 0; i--) {heapifyDown(height, i);}

        while(l > 1) {
            result[l - 1] ^= result[0];
            result[0] ^= result[l - 1];
            result[l - 1] ^= result[0];
            l--;
            heapifyDown(height, 1);
        }

        int left = result[0];
        int right = result[1];
        l = height.size();

        if (left > right) {
            left ^= right;
            right ^= left;
            left ^= right;
        }

        int water = calcW(height, left, right);

        for(int i = 2; i < l; i++) {
            if (left == 0 && right == l-1) {break;}
            if(result[i] > left && result[i] < right) {continue;}

            int tmp;
            if (result[i] > right) {
                tmp = calcW(height, left, (right = result[i]));
            }
            else {
                tmp = calcW(height, (left = result[i]), right);
            }
            if (tmp > water) {water = tmp;}
        }

        return water;
    }

private:
    int l;
    vector<int> result;

    void heapifyDown(vector<int>& nums, int index) {
        int c = nums[result[index - 1]];

        if (index <= (l/2)) {
            int left = nums[result[(2 * index) - 1]];

            int right = INT_MAX;
            if ((2 * index) + 1 <= l) {
                right = nums[result[2 * index]];
            }

            if (left <= right && c > left) {
                result[index - 1] ^= result[(2 * index) - 1];
                result[(2 * index) - 1] ^= result[index - 1];
                result[index - 1] ^= result[(2 * index) - 1];
                heapifyDown(nums, 2 * index);
            }
            else if (left > right && c > right) {
                result[index - 1] ^= result[2 * index];
                result[2 * index] ^= result[index - 1];
                result[index - 1] ^= result[2 * index];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }

    int calcW(vector<int>& nums, int& left, int& right) {
        return (right - left) * std::min(nums[left], nums[right]);
    }
};
