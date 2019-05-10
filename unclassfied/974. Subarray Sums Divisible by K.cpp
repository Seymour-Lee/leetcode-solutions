// TLE
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> sums(A.size()+1, 0);
        for(int i = 0; i < A.size(); i++) sums[i+1] = sums[i]+A[i];
        int ans = 0;
        for(int i = 0; i < sums.size(); i++){
            for(int j = i+1; j < sums.size(); j++){
                if((sums[j] - sums[i]) % K == 0) ans++;
            }
        }
        return ans;
    }
};

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> sums(A.size()+1, 0);
        for(int i = 0; i < A.size(); i++) sums[i+1] = sums[i]+A[i];
        unordered_map<int, int> yu2num;
        for(auto s: sums) yu2num[(s+K*10000)%K]++;
        int ans = 0;
        for(auto p: yu2num) ans += p.second * (p.second-1) / 2;
        return ans;
    }
};