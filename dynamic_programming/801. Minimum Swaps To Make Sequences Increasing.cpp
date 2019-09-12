class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int noPrev = 0;
        int swapPrev = 1;
        for(int i = 1; i < A.size(); i++){
            int noCur = A.size(), swapCur = A.size();
            if(A[i-1] < A[i] && B[i-1] < B[i]){
                noCur = noPrev;
                swapCur = swapPrev+1;
            }
            if(A[i-1] < B[i] && B[i-1] < A[i]){
                noCur = min(noCur, swapPrev);
                swapCur = min(swapCur, noPrev+1);
            }
            noPrev = noCur;
            swapPrev = swapCur;
        }
        return min(noPrev, swapPrev);
    }
};

class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int noPrev = 0;
        int swapPrev = 1;
        for(int i = 1; i < A.size(); i++){
            int noCur = A.size(), swapCur = A.size();
            if(A[i-1] < A[i] && B[i-1] < B[i]){
                noCur = noPrev;
                swapCur = swapPrev+1;
            }
            if(A[i-1] < B[i] && B[i-1] < A[i]){
                noCur = min(noCur, swapPrev);
                swapCur = min(swapCur, noPrev+1);
            }
            noPrev = noCur;
            swapPrev = swapCur;
        }
        return min(noPrev, swapPrev);
    }
};