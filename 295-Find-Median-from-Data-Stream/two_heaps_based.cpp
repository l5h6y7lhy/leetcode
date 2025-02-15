class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (p2.empty()) {
            p2.push_back(num);
            return;
        }

        if (p1.empty()) {
            if (num >= p2[0]) {
                p1.push_back(p2[0]);
                p2[0] = num;
            }
            else {
                p1.push_back(num);
            }

            return;
        }

        if (num >= p2[0]) {
            if (p2.size() > p1.size()) {
                p1.push_back(p2[0]);
                heapifyUpp1(p1.size());
                p2[0] = num;
                heapifyDownp2(1);
            }
            else {
                p2.push_back(num);
                heapifyUpp2(p2.size());
            }
        }
        else if (num <= p1[0]){
            if (p2.size() == p1.size()) {
                p2.push_back(p1[0]);
                heapifyUpp2(p2.size());
                p1[0] = num;
                heapifyDownp1(1);
            }
            else {
                p1.push_back(num);
                heapifyUpp1(p1.size());
            }
        }
        else {
            if (p2.size() == p1.size()) {
                p2.push_back(num);
                heapifyUpp2(p2.size());
            }
            else {
                p1.push_back(num);
                heapifyUpp1(p1.size());
            }
        }
    }

    double findMedian() {
        if (p2.size() > p1.size()) {
            return ((double) p2[0]);
        }

        return (p1[0] + p2[0]) / 2.0;
    }

private:
    vector<int> p1, p2;

    void heapifyUpp1(int index) {
        if (index > 1) {
            int parent = index / 2;

            if (p1[index - 1] > p1[parent - 1]) {
                p1[index - 1] ^= p1[parent - 1];
                p1[parent - 1] ^= p1[index - 1];
                p1[index - 1] ^= p1[parent - 1];
                heapifyUpp1(parent);
            }
        }
    }

    void heapifyUpp2(int index) {
        if (index > 1) {
            int parent = index / 2;

            if (p2[index - 1] < p2[parent - 1]) {
                p2[index - 1] ^= p2[parent - 1];
                p2[parent - 1] ^= p2[index - 1];
                p2[index - 1] ^= p2[parent - 1];
                heapifyUpp2(parent);
            }
        }
    }

    void heapifyDownp1(int index) {
        int l = p1.size();
        int c = p1[index - 1];

        if (index <= (l/2)) {
            int left = p1[(2 * index) - 1];
            int right = INT_MIN;

            if ((2 * index) + 1 <= l) {
                right = p1[2 * index];
            }

            if (left >= right && c < left) {
                p1[index - 1] ^= p1[(2 * index) - 1];
                p1[(2 * index) - 1] ^= p1[index - 1];
                p1[index - 1] ^= p1[(2 * index) - 1];
                heapifyDownp1(2 * index);
            }
            else if (left < right && c < right) {
                p1[index - 1] ^= p1[2 * index];
                p1[2 * index] ^= p1[index - 1];
                p1[index - 1] ^= p1[2 * index];
                heapifyDownp1((2 * index) + 1);
            }
        }

        return;
    }

    void heapifyDownp2(int index) {
        int l = p2.size();
        int c = p2[index - 1];

        if (index <= (l/2)) {
            int left = p2[(2 * index) - 1];
            int right = INT_MAX;

            if ((2 * index) + 1 <= l) {
                right = p2[2 * index];
            }

            if (left <= right && c > left) {
                p2[index - 1] ^= p2[(2 * index) - 1];
                p2[(2 * index) - 1] ^= p2[index - 1];
                p2[index - 1] ^= p2[(2 * index) - 1];
                heapifyDownp2(2 * index);
            }
            else if (left > right && c > right) {
                p2[index - 1] ^= p2[2 * index];
                p2[2 * index] ^= p2[index - 1];
                p2[index - 1] ^= p2[2 * index];
                heapifyDownp2((2 * index) + 1);
            }
        }

        return;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
