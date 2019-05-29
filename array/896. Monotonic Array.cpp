class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        return increase(A) || decrease(A);
    }
    
private:
    bool increase(vector<int> &vec){
        for(decltype(vec.size()) i = 0; i != vec.size()-1; i++){
            if(vec[i] > vec[i+1]) return false;
        }
        return true;
    }
    
    bool decrease(vector<int> &vec){
        for(decltype(vec.size()) i = 0; i != vec.size()-1; i++){
            if(vec[i] < vec[i+1]) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size() <= 2) return true;
        int i = 1, j = A.size()-2;
        for(; i < A.size() && A[i-1] <= A[i]; i++);
        for(; j >= 0 && A[j] >= A[j+1]; j--);
        return i == A.size() || j == -1;
    }
};