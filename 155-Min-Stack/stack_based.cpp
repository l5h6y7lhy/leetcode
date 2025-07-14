class MinStack {
public:
    MinStack() {
        result = INT_MAX;
    }

    void push(int val) {
        if (val < result) {
            m[val] = result;
            result = val;
        }

        t[val]++;
        s.push(val);
    }

    void pop() {
        t[s.top()]--;

        if (s.top() == result && !t[s.top()]) {result = m[s.top()];}

        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return result;
    }

private:
    stack<int> s;
    unordered_map<int, int> m, t;
    int result;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
