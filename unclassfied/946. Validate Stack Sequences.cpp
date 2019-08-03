class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() <= 2) return true;
        stack<int> stk;
        int i = 0;
        for(auto num: pushed){
            if(num == popped[i]){
                i++;
                while(stk.empty() == false && stk.top() == popped[i]){
                    stk.pop();
                    i++;
                }
            }
            else{
                stk.push(num);
            }
        }
        while(stk.empty() == false){
            if(stk.top() != popped[i]) return false;
            stk.pop();
            i++;
        }
        return true;
    }
};

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() <= 2) return true;
        stack<int> stk;
        int i = 0;
        for(auto num: pushed){
            if(num == popped[i]){
                i++;
                while(stk.empty() == false && stk.top() == popped[i]){
                    stk.pop();
                    i++;
                }
            }
            else{
                stk.push(num);
            }
        }
        while(stk.empty() == false){
            if(stk.top() != popped[i]) return false;
            stk.pop();
            i++;
        }
        return true;
    }
};