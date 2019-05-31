class Solution {
public:
    bool isHappy(int n) {
        set<int> s{n};
        int next = 0;
        while(n != 1){
            next = 0;
            while(n){
                next += (n % 10) * (n % 10);
                n = n / 10;
            }
            if(s.find(next) != s.end()) return false;
            s.insert(next);
            n = next;
        }
        return true;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        if(n <= 0) return false;
        unordered_set<int> seen;
        while(n != 1){
            if(seen.find(n) != seen.end()) return false;
            seen.insert(n);
            int next = 0;
            while(n) next += (n%10)*(n%10), n /= 10;
            n = next;
        }
        return true;
    }
};