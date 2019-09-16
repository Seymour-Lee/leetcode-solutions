class Solution {
public:
    int countLetters(string s) {
        vector<int> len(26, 0);
        int i = 0, j = 0;
        while(i <= j && j < s.size()){
            if(s[i] != s[j]) len[s[i]-'a'] += (1+j-i)*(j-i)/2, i = j;
            j++;
        }
        len[s[i]-'a'] += (1+j-i)*(j-i)/2;
        return accumulate(len.begin(), len.end(), 0);
    }
};