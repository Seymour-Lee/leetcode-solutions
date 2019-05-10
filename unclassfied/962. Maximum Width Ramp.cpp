class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int ans = 0;
        map<int, int> num1st;
        map<int, int> num2nd;
        for(int i = 0; i < A.size(); i++) num2nd[A[i]] = i;
        for(int i = A.size()-1; i >= 0; i--) num1st[A[i]] = i;
        int minpos = INT_MAX;
        for(auto &p: num1st){
            minpos = min(p.second, minpos);
            p.second = minpos;
        }
        for(auto p: num2nd){
            ans = max(ans, p.second-num1st[p.first]);
        }
        return ans;
    }
};