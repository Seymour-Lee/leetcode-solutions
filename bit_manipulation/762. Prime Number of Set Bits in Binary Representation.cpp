class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int result = 0;
        for(int i = L; i <= R; i++){
            if(IsPrime(BitCounter(i))){
                result++;
            }
        }
        return result;
    }
    
private:
    bool IsPrime(int x){
        return x==2 || x==3 || x==5 || x==7 || x==11 ||
             x==13 || x==17 || x==19;
    }
    
    int BitCounter(int x){
        return x == 0? 0: BitCounter(x/2) + (x & 1);
    }
};

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        vector<bool> dp(32, false);
        dp[2] = dp[3] = dp[5] = dp[7] = dp[11] = dp[13] = dp[17] = dp[19] = dp[23] = dp[29] = dp[31] = true;
        int ans = 0;
        for(int i = L; i <= R; i++){
            int counter = 0;
            for(int j = 0; j < 32; j++) if(((i>>j)&1) == 1) counter++;
            if(dp[counter]) ans++;
        }
        return ans;
    }
};