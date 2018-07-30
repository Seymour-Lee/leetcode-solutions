class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        back.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(front.empty()){
            while(back.empty() == false){
                front.push(back.top());
                back.pop();
            }
        }
        int top = front.top();
        front.pop();
        return top;
    }
    
    /** Get the front element. */
    int peek() {
        if(front.empty()){
            while(back.empty() == false){
                front.push(back.top());
                back.pop();
            }
        }
        return front.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return front.empty() && back.empty();
    }
    
private:
    stack<int> front; //the stack where get the front element of the queue: front, pop
    stack<int> back;  //the stack where push the new element to the queue: push
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */