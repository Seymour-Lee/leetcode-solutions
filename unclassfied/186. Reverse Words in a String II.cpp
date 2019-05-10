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