class Solution {
public:
    int subtractProductAndSum(int n) {
        int sum = 0;
        int pro = 1;
        string num = to_string(n);
        for(auto c: num){
            int a = c-'0';
            sum += a;
            pro *= a;
        }
        return pro-sum;
    }
};