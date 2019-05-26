class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto &a: A) a = a * a;
        sort(A.begin(), A.end());
        return A;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        for(auto &a: A) a = a*a;
        sort(A.begin(), A.end());
        return A;
    }
};

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0, j = A.size()-1;
        vector<int> ans(A.size(), 0);
        int pos = j;
        while(i <= j){
            if(abs(A[i]) < abs(A[j])){
                ans[pos--] = A[j]*A[j];
                j--;
            }
            else{
                ans[pos--] = A[i]*A[i];
                i++;
            }
        }
        return ans;
    }
};