class Solution {
public:
    int kthGrammar(int N, int K) {
        if(K == 1) return 0;
        if(K == 2) return 1;
        if(K % 2 == 1) return kthGrammar(-1, (K+1) / 2);
        else return 1-kthGrammar(-1, K / 2);
    }
};