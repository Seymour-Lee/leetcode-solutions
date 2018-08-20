class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long length = 0;
        int size = S.size();
        for(auto c: S) length = isdigit(c)? length*(c-'0'): length+1;
        for(int i = size-1; i >= 0; i--){
            K = K % length;
            if(K == 0 && isalpha(S[i])) return string("") + S[i];
            if(isdigit(S[i])) length = length / (S[i] - '0');
            else length--;
        }
        return "";
    }
};