class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int result = INT_MAX;
        if(triangle.size() == 0) return result;
        vector<vector<int>> dp(triangle.size(), vector<int>());
        dp[0] = triangle[0];
        for(decltype(triangle.size()) r = 1; r != triangle.size(); r++){
            for(decltype(triangle[0].size()) c = 0; 
                c != triangle[r].size(); c++){
                if(c == 0){
                    dp[r].push_back(dp[r-1][c] + triangle[r][c]);
                }
                else if(c == triangle[r].size()-1){
                    dp[r].push_back(dp[r-1][c-1] + triangle[r][c]);
                }
                else{
                    dp[r].push_back(min(dp[r-1][c-1], dp[r-1][c]) 
                                    + triangle[r][c]);
                }
            }
        }
        for(auto res: dp.back()){
            result = min(res, result);
        }
        return result;
    }
};

class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        for(int i = 1; i < t.size(); i++){
            for(int j = 0; j < t[i].size(); j++){
                int l = j-1 >= 0? t[i-1][j-1]: INT_MAX;
                int r = j < t[i-1].size()? t[i-1][j]: INT_MAX;
                t[i][j] += min(l, r);
            }
        }
        return *min_element(t.back().begin(), t.back().end());
    }
};