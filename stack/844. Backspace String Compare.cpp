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

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string s, t;
        for(auto c: S){
            if(c == '#'){
                if(s.size()) s.pop_back();
            }
            else s += c;
        }
        for(auto c: T){
            if(c == '#'){
                if(t.size()) t.pop_back();
            }
            else t += c;
        }
        return s == t;
    }
};