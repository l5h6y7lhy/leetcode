
class SparseVector {
public:
    SparseVector(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]) {r[i] = nums[i];}
        }
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        if (getSize() > vec.getSize()) {
            return vec.dotProduct(*this);
        }

        int result = 0;

        for (auto it = r.begin(); it != r.end(); ++it) {
            if (vec.exist(it->first)) {
                result += (vec.at(it->first) * it->second);
            }
        }

        return result;
    }

    int at(int index) {return r[index];}
    bool exist(int index) {return (r.find(index) != r.end());}
    int getSize() {return r.size();}

private:
    unordered_map<int, int> r;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
