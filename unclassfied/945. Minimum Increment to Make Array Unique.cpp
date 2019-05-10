class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() <= 1) return 0;
        int n = A.size();
        sort(A.begin(), A.end());
        int prev = A[0];
        int ans = 0;
        for(int i = 1; i < n; i++){
            if(A[i] <= prev){
                ans += prev-A[i]+1;
                A[i] = prev + 1;
                prev = A[i];
            }
            else{
                prev = A[i];
            }
        }
        return ans;
    }
};