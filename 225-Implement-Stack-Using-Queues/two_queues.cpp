class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        if (q2.empty()) {q1.push(x);}
        else {q2.push(x);}
        return;
    }

    int pop() {
        int result;

        if (q2.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }

            result = q1.front();
            q1.pop();
        }
        else {
            while (q2.size() > 1) {
                q1.push(q2.front());
                q2.pop();
            }

            result = q2.front();
            q2.pop();
        }

        return result;
    }

    int top() {
        int result;

        if (q2.empty()) {
            while (q1.size() > 0) {
                q2.push((result = q1.front()));
                q1.pop();
            }
        }
        else {
            while (q2.size() > 0) {
                q1.push((result = q2.front()));
                q2.pop();
            }
        }

        return result;
    }

    bool empty() {
        return (q1.empty() && q2.empty());
    }

private:
    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
