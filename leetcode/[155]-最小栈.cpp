class MinStack {
    vector<int> nums;
    vector<int> minvalue;
public:
    /** initialize your data structure here. */
    MinStack() {
        minvalue.push_back(INT_MAX);
    }

    void push(int x) {
        nums.push_back(x);
        minvalue.push_back(min(minvalue.back(), x));
    }

    void pop() {
        nums.pop_back();
        minvalue.pop_back();
    }

    int top() {
        return nums.back();
    }

    int getMin() {
        return minvalue.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */