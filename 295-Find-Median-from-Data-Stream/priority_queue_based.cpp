class MedianFinder {
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (q1.empty()) {
            q1.push(num);
            return;
        }

        if (q2.empty()) {
            if (num >= q1.top()) {
                q2.push(num * (-1));
            }
            else {
                q2.push(q1.top() * (-1));
                q1.pop();
                q1.push(num);
            }

            return;
        }

        int l = q1.top();
        int r = q2.top() * (-1);

        if (num <= l) {
            if (q1.size() > q2.size()) {
                q1.pop();
                q2.push(l * (-1));
            }

            q1.push(num);
        }
        else if (num >= r) {
            if (q1.size() == q2.size()) {
                q2.pop();
                q1.push(r);
            }

            q2.push(num * (-1));
        }
        else {
            if (q1.size() == q2.size()) {
                q1.push(num);
            }
            else {
                q2.push(num * (-1));
            }
        }
    }

    double findMedian() {
        if (q1.size() > q2.size()) {
            return ((double) q1.top());
        }

        return (q1.top() - q2.top()) / 2.0;
    }

private:
    priority_queue<int> q1, q2;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
