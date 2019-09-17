class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int result = 0;
        int base = 0;
        while(base < n){
            int end = base;
            if(end + 1 < n && A[end] < A[end+1]){
                while(end + 1 < n && A[end] < A[end+1]) end++;
                if(end + 1 < n && A[end] > A[end+1]){
                    while(end+1 < n && A[end] > A[end+1]) end++;
                    result = max(result, end-base+1);
                }
            }
            base = max(end, base+1);
        }
        return result;
    }
};

class Solution {
public:
    int longestMountain(vector<int>& A) {
        if(A.size() < 3) return 0;
        vector<int> up(A.size(), 1), dw(A.size(), 1);
        for(int i = 1; i < A.size(); i++) if(A[i-1] < A[i]) up[i] = up[i-1]+1;
        for(int i = A.size()-2; i >= 0; i--) if(A[i] > A[i+1]) dw[i] = dw[i+1]+1;
        int ans = 0;
        for(int i = 0; i < A.size(); i++) if(up[i] != 1 && dw[i] != 1) ans = max(ans, up[i]+dw[i]-1);
        return ans >= 3? ans: 0;
    }
};