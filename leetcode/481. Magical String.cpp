class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        for(int i = 2; s.size() <= n; i++){
            if(s[i] == '2'){
                if(s.back() == '1') s += "22";
                else s += "11";
            }
            else{
                if(s.back() == '1') s += "2";
                else s += "1";
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '1') ans++;
        }
        return ans;
    }
};