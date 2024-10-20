class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return Median_SingleVector(nums2);
        }

        if (nums2.empty()) {
            return Median_SingleVector(nums1);
        }

        p1 = 0;
        p2 = 0;
        int num1L = nums1.size();
        int num2L = nums2.size();

        if (num1L == num2L) {
            BinarySearch(nums1, nums2, num1L);
        }
        else if (num1L > num2L) {
            p1 += AddOffset(num1L, num2L);
            BinarySearch(nums1, nums2, num2L);
        }
        else {
            p2 += AddOffset(num2L, num1L);
            BinarySearch(nums1, nums2, num1L);
        }

        int m2;
        if (p1 == num1L) {m2 = nums2[p2];}
        else if (p2 == num2L) {m2 = nums1[p1];}
        else {
            m2 = (nums1[p1] < nums2[p2]) ? nums1[p1] : nums2[p2];
        }

        if ((num1L + num2L) % 2) {return ((double) m2);}

        int m1;
        if (p1 == 0) {m1 = nums2[p2 - 1];}
        else if (p2 == 0) {m1 = nums1[p1 - 1];}
        else {
            m1 = (nums1[p1 - 1] > nums2[p2 - 1]) ? nums1[p1 - 1] : nums2[p2 - 1];
        }

        return ((double) (m1 + m2)) / 2.0;
    }

private:
    int p1;
    int p2;

    double Median_SingleVector(vector<int>& a) {
        int s;

        if ((s=a.size()) % 2 == 0){
            return ((double) (a[s/2] + a[(s/2)-1])) / 2.0;
        }

        return ((double) a[s/2]);
    }

    void BinarySearch(vector<int>& nums1, vector<int>& nums2, int l) {
        if (l == 1) {
            (nums1[p1] < nums2[p2]) ? p1++ : p2++;
            return;
        }

        int h = l/2;
        int inc = l - h;
        (nums1[p1+h] < nums2[p2+h]) ? p1+=inc : p2+=inc;

        BinarySearch(nums1, nums2, h);
    }

    int AddOffset(int lf, int sf) {
        int lh = lf / 2;
        int sh = sf / 2;

        if(lf % 2 == 0 && sf % 2 == 1) {return lh - sh - 1;}
        return lh - sh;
    }
};
