class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 0) return false;
        int sum = 1;
        int n = sqrt(num);
        for(int i = 2; i <= n; i++){
            if(num % i == 0){
                sum += i + (num / i);
            }
        }
        if(n * n == num) sum -= n;
        return sum == num;
    }
};