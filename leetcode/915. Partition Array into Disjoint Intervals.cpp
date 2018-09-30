class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> maxl2r(A.size(), A[0]);
        vector<int> minr2l(A.size(), A.back());
        for(int i = 1; i < A.size(); i++) maxl2r[i] = max(maxl2r[i-1], A[i]);
        for(int i = A.size()-2; i >= 0; i--) minr2l[i] = min(minr2l[i+1], A[i]);
        for(int i = 0; i < A.size()-1; i++)
            if(maxl2r[i] <= minr2l[i+1])
                return i+1;
        return 1;
    }
};