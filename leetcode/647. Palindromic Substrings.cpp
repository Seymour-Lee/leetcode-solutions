class Solution {
public:
    int countSubstrings(string s) {
        if(s.size() == 0) return 0;
        vector<int> sums = {1};
        int result = 1;
        for(int i = 1; i < s.size(); i++){
            sums.push_back(1);
            for(int j = i - 1; j >= 0; j--){
                if(isPalindromic(s.substr(j, i-j+1))){
                    sums[i]++;
                }
            }
            result += sums.back();
        }
        return result;
    }
    
private:
    bool isPalindromic(string s){
        for(int i = 0, j = s.size() - 1; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }
};