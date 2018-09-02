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