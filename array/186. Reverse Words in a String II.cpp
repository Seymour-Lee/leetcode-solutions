class Solution {
public:
    void reverseWords(vector<char>& str) {
        reverse(str.begin(), str.end());
        int start = 0;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == ' '){
                reverse(str.begin()+start, str.begin()+i);
                start = i+1;
            }
        }
        reverse(str.begin()+start, str.end());
    }
};

class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int l = 0, r = 0;
        while(l <= r && r < s.size()){
            if(s[r] != ' ') r++;
            else{
                reverse(s.begin()+l, s.begin()+r);
                l = r+1, r++;
            }
        }
        reverse(s.begin()+l, s.end());
    }
};