class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> ans(s.size()+1);
        for(int i = 0; i < ans.size(); i++) ans[i] = i+1;
        int i = 0, j = 0;
        while(i < s.size() && s[i] == 'I') i++; 
        j = i+1;
        while(i < s.size() && j < s.size()){
            while(j < s.size() && s[j] == 'D') j++;
            if(j == s.size()) break;
            reverse(ans.begin()+i, ans.begin()+j+1);
            i = j;
            while(i < s.size() && s[i] == 'I') i++;
            j = i+1;
        }
        reverse(ans.begin()+i, ans.end());
        return ans;
    }
};