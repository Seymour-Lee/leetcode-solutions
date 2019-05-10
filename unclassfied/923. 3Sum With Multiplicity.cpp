class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int modulo = 1e9+7;
        sort(A.begin(), A.end());
        long ans = 0;
        for(int i = 0; i < A.size(); i++){
            int t = target - A[i];
            int l = i+1, r = A.size()-1;
            while(l < r){
                if(A[l]+A[r] < t){
                    l++;
                }
                else if(A[l]+A[r] > t){
                    r--;
                }
                else{ // equel
                    if(A[l] != A[r]){
                        int lcount = 1, rcount = 1;
                        while(l+1 < r && A[l] == A[l+1]) l++, lcount++;
                        while(r-1 > l && A[r] == A[r-1]) r--, rcount++;
                        ans += lcount * rcount;
                        ans = ans % modulo;
                        l++, r--;
                    }
                    else{
                        ans += (r-l+1)*(r-l)/2;
                        ans = ans % modulo;
                        break;
                    }
                }
            }
        }
        return (int)ans;
    }
};