class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int n = A.size();
        int len = A[0].size();
        int ans = 0;
        auto f = [](vector<string> &strs){
            for(int i = 1; i < strs.size(); i++){
                if(strs[i] < strs[i-1]) return false;
            }
            return true;
        };
        vector<string> cur(n, "");
        for(int j = 0; j < len; j++){
            vector<string> next = cur;
            for(int i = 0; i < n; i++) next[i] += A[i][j];
            if(f(next)) cur = next;
            else ans++;
        }
        return ans;
    }
};