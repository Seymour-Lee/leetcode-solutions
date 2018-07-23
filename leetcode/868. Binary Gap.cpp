class Solution {
public:
    int binaryGap(int N) {
        while((N & 1) == 0) N = N >> 1;
        if(N == 1) return 0;
        int longest = 0;
        int last = 0;
        for(int i = 0; N; i++, N = N >> 1){
            if(N & 1){
                longest = i - last > longest? i-last: longest;
                last = i;
            }
        }
        return longest;
    }
};