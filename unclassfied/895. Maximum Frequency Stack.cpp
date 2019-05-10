class FreqStack {
public:
    FreqStack() {
        mostFreq = 0;
    }
    
    void push(int x) {
        mostFreq = max(mostFreq, ++num2freq[x]);
        freq2nums[num2freq[x]].push(x);
    }
    
    int pop() {
        int ans = freq2nums[mostFreq].top();
        freq2nums[mostFreq].pop();
        if(freq2nums[mostFreq].size() == 0) mostFreq--;
        num2freq[ans]--;
        return ans;
    }
    
private:
    map<int, int> num2freq;
    map<int, stack<int>> freq2nums;
    int mostFreq;
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */