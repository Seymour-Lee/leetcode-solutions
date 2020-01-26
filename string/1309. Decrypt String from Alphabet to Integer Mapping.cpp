class Solution {
public:
    string freqAlphabets(string s) {
        int i = 0;
        string ans = "";
        while(i < s.size()){
            if(i+2 < s.size() && s[i+2] == '#'){
                ans += char(stoi(s.substr(i, 2))-1+'a');
                i += 3;
            }
            else{
                ans += char(s[i]-'1'+'a');
                i++;
            }
        }
        return ans;
    }
};