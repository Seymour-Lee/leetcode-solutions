class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int result = 10;
        int cur = 9;
        int have = 9;
        while(--n && have > 0){
            cur = cur * have;
            result += cur;
            have--;
        }
        return result;
    }
};