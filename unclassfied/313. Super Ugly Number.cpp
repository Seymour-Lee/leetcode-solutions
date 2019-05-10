class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ugly(n+1, 0);
        ugly[0] = 1;
        vector<int> pointer(primes.size());
        for(int i = 1; i < n; i++){
            int smallest = INT_MAX;
            int idx = 0;
            for(int j = 0; j < primes.size(); j++){
                if(ugly[pointer[j]] * primes[j] < smallest){
                    smallest = ugly[pointer[j]] * primes[j];
                    idx = j;
                }
                else if(ugly[pointer[j]] * primes[j] == smallest){
                    pointer[j]++;
                }
            }
            ugly[i] = smallest;
            pointer[idx]++;
        }
        return ugly[n-1];
    }
};