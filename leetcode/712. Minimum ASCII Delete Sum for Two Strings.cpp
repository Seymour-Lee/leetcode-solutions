class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = s1.size()-1; i >= 0; i--) 
            dp[i][s2.size()] = dp[i+1][s2.size()] + s1[i];
        for(int i = s2.size()-1; i >= 0; i--)
            dp[s1.size()][i] = dp[s1.size()][i+1] + s2[i];
        for(int i = s1.size()-1; i >= 0; i--){
            for(int j = s2.size()-1; j >= 0; j--){
                if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = min(dp[i+1][j] + s1[i], dp[i][j+1] + s2[j]);
                }
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        for(int i = s1.size()-1; i >= 0; i--) dp[i][s2.size()] = dp[i+1][s2.size()]+s1[i];
        for(int i = s2.size()-1; i >= 0; i--) dp[s1.size()][i] = dp[s1.size()][i+1]+s2[i];
        for(int i = s1.size()-1; i >= 0; i--){
            for(int j = s2.size()-1; j >= 0; j--){
                dp[i][j] = s1[i] == s2[j]?
                    dp[i+1][j+1]:
                    min(dp[i+1][j]+s1[i], dp[i][j+1]+s2[j]);
            }
        }
        return dp[0][0];
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, 0));
        int len1 = s1.size(), len2 = s2.size();
        for(int l1 = 1; l1 <= len1; l1++) dp[l1][0] = dp[l1-1][0] + s1[l1-1];
        for(int l2 = 1; l2 <= len2; l2++) dp[0][l2] = dp[0][l2-1] + s2[l2-1];
        for(int l1 = 1; l1 <= len1; l1++){
            for(int l2 = 1; l2 <= len2; l2++){
                dp[l1][l2] = s1[l1-1] == s2[l2-1]?
                    dp[l1-1][l2-1]:
                    min(dp[l1-1][l2]+s1[l1-1], dp[l1][l2-1]+s2[l2-1]);
            }
        }
        return dp.back().back();
    }
};

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i = 1; i <= l1; i++) dp[i][0] = dp[i-1][0] + s1[i-1];
        for(int j = 1; j <= l2; j++) dp[0][j] = dp[0][j-1] + s2[j-1];
        for(int i = 0; i < l1; i++) for(int j = 0; j < l2; j++){
            dp[i+1][j+1] = s1[i] == s2[j]?
                           dp[i][j]:
                           min(dp[i][j+1]+s1[i], dp[i+1][j]+s2[j]);
        }
        return dp[l1][l2];
    }
};