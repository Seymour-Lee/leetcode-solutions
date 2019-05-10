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