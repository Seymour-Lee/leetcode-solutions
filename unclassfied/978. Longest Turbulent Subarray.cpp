class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() <= 1) return A.size();
        int ans = 1;
        vector<int> up(A.size(), 1);
        vector<int> down(A.size(), 1);
        for(int i = 1; i < A.size(); i++){
            if(A[i-1] < A[i]) up[i] = down[i-1]+1, ans = max(ans, up[i]);
            if(A[i-1] > A[i]) down[i] = up[i-1]+1, ans = max(ans, down[i]);
        }
        return ans;
    }
};