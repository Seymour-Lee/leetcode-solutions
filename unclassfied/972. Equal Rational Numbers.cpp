class Solution {
public:
    bool isRationalEqual(string S, string T) {
        return f(S) == f(T);
    }
    
private:
    double f(string str){
        auto i = str.find("(");
        if(i != string::npos){
            string base = str.substr(0, i);
            string repl = str.substr(i+1, str.size()-i-2);
            for(int i = 0; i < 20; i++) base += repl;
            return stod(base);
        }
        return stod(str);
    }
};