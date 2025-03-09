class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        l = nums.size();
        half = l / 2;
        ul = l - 1;

        if (l % 2 == 0) {half--;}
        if (l % 2 == 1) {ul--;}

        for (int i = l / 2; i > 0; i--) {heapifyDown(nums, i);}

        while(l > 1) {
            nums[coordinate(l - 1)] ^= nums[coordinate(0)];
            nums[coordinate(0)] ^= nums[coordinate(l - 1)];
            nums[coordinate(l - 1)] ^= nums[coordinate(0)];
            l--;
            heapifyDown(nums, 1);
        }

        return;
    }

private:
    int l;
    int half;
    int ul;

    int coordinate(int i) {
        if (i <= half) {return (half - i) * 2;}
        return ul - (2 * (i - half - 1));
    }

    void heapifyDown(vector<int>& nums, int index) {
        int c = nums[coordinate(index - 1)];

        if (index <= (l/2)) {
            int left = nums[coordinate((2 * index) - 1)];

            int right = INT_MIN;
            if ((2 * index) + 1 <= l) {
                right = nums[coordinate(2 * index)];
            }

            if (left >= right && c < left) {
                nums[coordinate(index - 1)] ^= nums[coordinate((2 * index) - 1)];
                nums[coordinate((2 * index) - 1)] ^= nums[coordinate(index - 1)];
                nums[coordinate(index - 1)] ^= nums[coordinate((2 * index) - 1)];
                heapifyDown(nums, 2 * index);
            }
            else if (left < right && c < right) {
                nums[coordinate(index - 1)] ^= nums[coordinate(2 * index)];
                nums[coordinate(2 * index)] ^= nums[coordinate(index - 1)];
                nums[coordinate(index - 1)] ^= nums[coordinate(2 * index)];
                heapifyDown(nums, (2 * index) + 1);
            }
        }

        return;
    }
};
