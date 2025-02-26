class MyQueue {
public:
    MyQueue() {

    }

    void push(int x) {
        while (!r2.empty()) {
            r1.push(r2.top());
            r2.pop();
        }

        r1.push(x);
    }

    int pop() {
        while (!r1.empty()) {
            r2.push(r1.top());
            r1.pop();
        }

        int result = r2.top();
        r2.pop();
        return result;
    }

    int peek() {
        while (!r1.empty()) {
            r2.push(r1.top());
            r1.pop();
        }

        return r2.top();
    }

    bool empty() {
        return (r1.empty() && r2.empty());
    }

private:
    stack<int> r1, r2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
