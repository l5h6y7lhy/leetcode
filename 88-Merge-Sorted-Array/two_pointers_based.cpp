class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = m - 1; i >= 0; i--) {
            nums1[i + n] = nums1[i];
        }

        int i1 = 0, i2 = 0;

        while (i1 < m && i2 < n) {
            if (nums1[i1 + n] < nums2[i2]) {
                nums1[i1 + i2] = nums1[i1 + n];
                i1++;
            }
            else {
                nums1[i1 + i2] = nums2[i2];
                i2++;
            }
        }

        while (i1 < m) {
            nums1[i1 + i2] = nums1[i1 + n];
            i1++;
        }

        while (i2 < n) {
            nums1[i1 + i2] = nums2[i2];
            i2++;
        }

        return;
    }
};
