class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if(min_stk.empty() || (!min_stk.empty() && x <= min_stk.top())){
            min_stk.push(x);
        }
    }
    
    void pop() {
        if(!min_stk.empty() && !stk.empty()){
            if(min_stk.top() == stk.top()){
                min_stk.pop();
            }
        }
        if(!stk.empty()) 
            stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }

private:
    stack<int> stk;
    stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(m.empty() || x <= m.top()) m.push(x);
    }
    
    void pop() {
        if(s.top() == m.top()) m.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m.top();
    }
    
private:
    stack<int> s;
    stack<int> m;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */