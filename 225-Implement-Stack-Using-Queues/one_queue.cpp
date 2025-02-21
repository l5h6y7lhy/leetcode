class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
        return;
    }

    int pop() {
        int count = q1.size();

        while (count > 1) {
            q1.push(q1.front());
            q1.pop();
            count--;
        }

        int result = q1.front();
        q1.pop();
        return result;
    }

    int top() {
        int count = q1.size();
        int result;

        while (count > 0) {
            q1.push((result = q1.front()));
            q1.pop();
            count--;
        }

        return result;
    }

    bool empty() {
        return q1.empty();
    }

private:
    queue<int> q1;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
