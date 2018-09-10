class Solution {
public:
    int lastRemaining(int n, bool l2r = true) {
        if(n == 1) return 1;
        if(l2r){
            return lastRemaining(n / 2, false) * 2;
        }
        else{
            if(n % 2 == 1){
                return lastRemaining(n / 2, true) * 2;
            }
            else{
                return lastRemaining(n / 2, true) * 2 - 1;
            }
        }
    }
};