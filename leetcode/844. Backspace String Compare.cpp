class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<int> stks;
        stack<int> stkt;
        for(auto c: S){
            if(c == '#'){
                if(stks.empty() == false) stks.pop();
            } 
            else stks.push(c);
        }
        for(auto c: T){
            if(c == '#'){
                if(stkt.empty() == false) stkt.pop();
            } 
            else stkt.push(c);
        }
        if(stks.size() != stkt.size()) return false;
        while(stks.empty() == false && stkt.empty() == false){
            if(stks.top() != stkt.top()) return false;
            stks.pop();
            stkt.pop();
        }
        return true;
    }
};