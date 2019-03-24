class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int ans = 0;
        int pos = A.size()-1;
        priority_queue<int, vector<int>, less<int>> pq;
        pq.push(A.back()-pos);
        for(int i = A.size()-2; i >= 0; i--){
            int cur = A[i]+i;
            ans = max(ans, pq.top()+cur);
            pq.push(A[i]-i);
        }
        return ans;
    }
};