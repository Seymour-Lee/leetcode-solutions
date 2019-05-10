class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int longest = 0;
        sort(pairs.begin(), pairs.end(), cmp);
        vector<int> cur(pairs.size(), 1);
        for(int i = 1; i < pairs.size(); i++){
            for(int j = 0; j < i; j++){
                cur[i] = max(pairs[j][1] < pairs[i][0]? cur[j]+1: 1, cur[i]);
                longest = cur[i] > longest? cur[i]: longest;
            }
        }
        return longest;
    }
    
    static bool cmp(vector<int> a, vector<int> b){
        return a[0] < b[0];
    }
};

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto f = [](vector<int> a, vector<int> b){return a[0] == b[0]? a[1]<b[1]: a[0]<b[0];};
        sort(pairs.begin(), pairs.end(), f);
        vector<int> dp(pairs.size(), 1);
        for(int i = 0; i < pairs.size(); i++){
            for(int j = 0; j < i; j++){
                if(pairs[j][1] < pairs[i][0]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};