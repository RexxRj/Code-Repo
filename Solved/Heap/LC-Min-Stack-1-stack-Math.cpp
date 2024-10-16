class MinStack {
    private:
    stack<long long> st;
    long long mini;
public:
    MinStack() {
        mini = INT_MIN;
    }
    
    void push(int value) {
        long long val = value;
        if(st.empty())
        {
            st.push(val);
            mini = val;
            return;
        }

        if(val<mini)
        {
            mini = 2*val - mini;
            st.push(mini);
            mini = val;
            return;
        }

        st.push(val);
        
    }
    
    void pop() {
        
        if(!st.empty() && st.top()<mini)
        {
            mini = 2*mini - st.top();
        }

        st.pop();
    }
    
    int top() {
        
        if(!st.empty() && st.top()<mini)
        return mini;
        return st.top();
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */