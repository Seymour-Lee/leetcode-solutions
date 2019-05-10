class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if(tokens.size() == 0) return 0;
        if(tokens.size() == 1) return P > tokens[0];
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0, j = n-1;
        int ans = 0;
        while(i <= j){
            if(tokens[i] <= P){
                P = P - tokens[i];
                ans++;
                i++;
            }
            else{
                if(ans == 0 || P + tokens[j] < tokens[i] || i == j) break;
                P = P + tokens[j];
                j--;
                ans--;
            }
        }
        return ans;
    }
};