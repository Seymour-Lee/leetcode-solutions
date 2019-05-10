class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.empty()) return 1;
        int last = b.back();
        b.pop_back();
        return powmod(superPow(a, b), 10) * powmod(a, last) % 1337;
    }
    
private:
    int powmod(int a, int k){
        a %= 1337;
        int result = 1;
        for(int i = 0; i < k; i++){
            result = (result * a) % 1337;
        }
        return result;
    }
};