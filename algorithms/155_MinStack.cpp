class MinStack {
public:
    stack<int> origin;
    stack<int> small;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        origin.push(x);
        if (small.empty() || x <= small.top()) {
            small.push(x);
        }
    }

    void pop() {
        if (origin.empty())
            return;

        if (!small.empty() && origin.top() == small.top()) {
            small.pop();
        }
        origin.pop();
    }

    int top() {
        return origin.top();
    }

    int getMin() {
        return small.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
