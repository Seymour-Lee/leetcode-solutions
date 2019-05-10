class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        string binary = "";
        while(N) binary = string(1, '0'+N%2)+binary, N /= 2;
        for(auto &c: binary) c = c == '1'? '0': '1';
        int ans = 0;
        for(auto c: binary) ans = ans*2+c-'0';
        return ans;
    }
};