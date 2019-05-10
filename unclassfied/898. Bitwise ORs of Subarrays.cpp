// TLE
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        if(A.size() == 0) return 0;
        set<int> result;
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
        for(decltype(A.size()) i = 0; i != A.size(); i++){
            dp[i][i] = A[i];
            result.insert(dp[i][i]);
        }
        for(decltype(dp.size()) i = 0; i != dp.size(); i++){
            for(decltype(dp[i].size()) j = i+1; j != dp[i].size(); j++){
                dp[i][j] = dp[i][j-1] | A[j];
                result.insert(dp[i][j]);
            }
        }
        return result.size();
    }
};

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        if(A.size() == 0) return 0;
        set<int> result;
        set<int> cur;
        cur.insert(0);
        for(auto a: A){
            set<int> cur2;
            for(auto e: cur) cur2.insert(a | e);
            cur2.insert(a);
            cur = cur2;
            for(auto e: cur) result.insert(e);
        }
        return result.size();
    }
};