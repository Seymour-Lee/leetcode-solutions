class Solution {
public:
    int minCut(string s) {
        if(s.size() <= 1) return 0;
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        vector<int> minCuts(s.size()+1, 0);
        for(int i = 0; i < minCuts.size(); i++) minCuts[i] = i-1;
        for(int j = 1; j < s.size(); j++){
            for(int i = j; i >= 0; i--){
                if(s[i] == s[j] && (j-i < 2 || isPalindrome[i+1][j-1])){
                    isPalindrome[i][j] = true;
                    minCuts[j+1] = min(minCuts[j+1], 1+minCuts[i]);
                }
            }
        }
        return minCuts.back();
    }
};

class Solution {
public:
    int minCut(string s) {
        if(s.size() <= 1) return 0;
        vector<vector<bool>> isPalindrome(s.size(), vector<bool>(s.size(), false));
        vector<int> minCuts(s.size()+1, 0);
        for(int i = 0; i < minCuts.size(); i++) minCuts[i] = i-1;
        for(int i = 0; i < s.size(); i++){
            for(int j = 0; j <= i; j++){
                if(s[i] == s[j] && (i-j < 2 || isPalindrome[j+1][i-1])){
                    isPalindrome[j][i] = true;
                    minCuts[i+1] = min(minCuts[i+1], 1+minCuts[j]);
                }
            }
        }
        return minCuts.back();
    }
};