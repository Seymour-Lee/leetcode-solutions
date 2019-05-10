class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int ans = 0;
        int n = A.size(), mod = 1e9+7;
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        stack<pair<int, int>> s1, s2;
        for(int i = 0; i < n; i++){
            int count = 1;
            while(s1.empty() == false && s1.top().first > A[i]){
                count += s1.top().second;
                s1.pop();
            }
            s1.push({A[i], count});
            left[i] = count;
        }
        for(int i = n-1; i >= 0; i--){
            int count = 1;
            while(s2.empty() == false && s2.top().first >= A[i]){
                count += s2.top().second;
                s2.pop();
            }
            s2.push({A[i], count});
            right[i] = count;
        }
        for(int i = 0; i < n; i++)
            ans = (ans + A[i]*left[i]*right[i]) % mod;
        return ans;
    }
};