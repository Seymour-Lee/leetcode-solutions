class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int sum = 0;
        for(auto a: A) if(a % 2 == 0) sum += a;
        for(auto q: queries){
            int val = q[0];
            int idx = q[1];
            int pre = A[idx];
            if(pre % 2 == 0) sum -= pre;
            A[idx] += val;
            if(A[idx] % 2 == 0) sum += A[idx];
            ans.push_back(sum);
        }
        return ans;
    }
};