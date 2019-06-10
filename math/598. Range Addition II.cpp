class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mina = m;
        int minb = n;
        for(auto op: ops){
            mina = min(mina, op[0]);
            minb = min(minb, op[1]);
        }
        return mina * minb;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minc = n;
        int minr = m;
        for(auto p: ops){
            minr = min(minr, p[0]);
            minc = min(minc, p[1]);
        }
        return minc * minr;
    }
};