class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        q1 = new queue<int>();
        q2 = new queue<int>();
        q = q1;
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q->push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> *next = q == q1? q2: q1;
        int size = q->size()-1;
        while(size--){
            next->push(q->front());
            q->pop();
        }
        int result = q->front();
        q->pop();
        q = next;
        return result;
    }
    
    /** Get the top element. */
    int top() {
        return q->back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q->empty();
    }
    
private:
    queue<int> *q1;
    queue<int> *q2;
    queue<int> *q;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */