class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int ans = 0;
        long l = stol(L);
        long r = stol(R);
        build("", ans, l, r);
        for(char ch = '0'; ch <= '9'; ch++) build(string(1, ch), ans, l, r);
        return ans;
    }
    
private:
    void build(string cur, int &ans, long l, long r){
        if(cur.size() > 9) return;
        if(cur.size() > 0 && cur[0] != '0'){
            long num = stol(cur);
            long power = num * num;
            if(power > r) return;
            if(power >= l && valid(to_string(power))) ans++;
        }
        for(char ch = '0'; ch <= '9'; ch++){
            build(string(1, ch)+cur+string(1, ch), ans, l, r);
        }
    }
    
    bool valid(string str){
        int l = 0, r = str.size()-1;
        while(l < r) if(str[l++] != str[r--]) return false;
        return true;
    }
};

class Solution {
public:
    int superpalindromesInRange(string L, string R) {
        int ans = 0;
        long l = stol(L);
        long r = stol(R);
        build("", ans, l, r);
        for(char ch = '0'; ch <= '9'; ch++) build(string(1, ch), ans, l, r);
        return ans;
    }
    
private:
    void build(string cur, int &ans, long l, long r){
        if(cur.size() > 9) return;
        if(cur.size() > 0 && cur[0] != '0'){
            long num = stol(cur);
            long power = num * num;
            if(power > r) return;
            if(power >= l && valid(to_string(power))) ans++;
        }
        for(char ch = '0'; ch <= '9'; ch++){
            build(string(1, ch)+cur+string(1, ch), ans, l, r);
        }
    }
    
    bool valid(string str){
        int l = 0, r = str.size()-1;
        while(l < r) if(str[l++] != str[r--]) return false;
        return true;
    }
};