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