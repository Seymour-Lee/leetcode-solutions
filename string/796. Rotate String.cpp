class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A.size() == 1 || A.size() == 0) return A == B;
        int size = A.size();
        while(size--){
            A = A.substr(1, A.size()-1) + A[0];
            if(A == B) return true;
        }
        return false;
    }
};

class Solution {
public:
    bool rotateString(string A, string B) {
        A = A + A;
        return A.size() == 2*B.size() && A.find(B) != string::npos;
    }
};