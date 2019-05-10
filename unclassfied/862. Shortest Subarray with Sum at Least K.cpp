class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        int ans = INT_MAX;
        vector<int> sums(n+1, 0);
        for(int i = 0; i < A.size(); i++) sums[i+1] = sums[i] + A[i];
        deque<int> q;
        for(int i = 0; i < n+1; i++){
            while(q.empty() == false && sums[i]-sums[q.front()] >= K){
                ans = min(ans, i-q.front());
                q.pop_front();
            }
            while(q.empty() == false && sums[i] <= sums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans == INT_MAX? -1: ans;
    }
};