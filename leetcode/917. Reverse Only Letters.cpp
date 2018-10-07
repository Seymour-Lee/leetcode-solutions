class Solution {
public:
    string reverseOnlyLetters(string S) {
        auto isletter = [](char ch){return ('a'<=ch&&ch<='z') || ('A'<=ch&&ch<='Z');};
        int i = 0, j = S.size()-1;
        while(i < j){
            while(isletter(S[i]) == false) i++;
            if(i >= j) break;
            while(isletter(S[j]) == false) j--;
            if(i >= j) break;
            swap(S[i++], S[j--]);
        }
        return S;
    }
};