class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        stk.push_back(x);
        auto ref = prev(stk.end());
        refs[x].push_back(ref);
    }
    
    int pop() {
        int val = stk.back();
        stk.pop_back();
        refs[val].pop_back();
        if(refs[val].size() == 0) refs.erase(val);
        return val;
    }
    
    int top() {
        return stk.back();
    }
    
    int peekMax() {
        return refs.rbegin()->first;
    }
    
    int popMax() {
        int val = refs.rbegin()->first;
        auto ref = refs[val].back();
        stk.erase(ref);
        refs[val].pop_back();
        if(refs[val].size() == 0) refs.erase(val);
        return val;
    }
    
private:
    list<int> stk;
    map<int, vector<list<int>::iterator>> refs;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */