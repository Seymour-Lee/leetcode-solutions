class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> ans(S.size()+1, 0);
        int i = 0, j = S.size();
        for(int k = 0 ;k < S.size(); k++){
            if(S[k] == 'I') ans[k] = i, i++;
            else ans[k] = j, j--;
        }
        ans.back() = i;
        return ans;
    }
};