class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> data;
    stack<int> minstack;
    MinStack() {

    }

    void push(int val) {
        data.push(val);
        if(minstack.empty() || val < minstack.top())
        {
            minstack.push(val);
        }
        else
        {
            minstack.push(minstack.top());
        }
    }

    void pop() {
        data.pop();
        minstack.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minstack.top();
    }
};
