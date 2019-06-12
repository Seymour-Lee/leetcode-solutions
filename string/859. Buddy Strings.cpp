class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A == "") return false;
        int i = 0, j = A.size()-1;
        while(i < A.size() && A[i] == B[i]) i++;
        while(j >= 0 && A[j] == B[j]) j--;
        if(i == j) return false;
        else if(i < j){
            swap(A[i], A[j]);
            return A == B;
        }
        else{
            set<char> s;
            for(auto c: A){
                if(s.find(c) != s.end()) return true;
                s.insert(c);
            }
            return false;
        }
    }
};

class Solution {
public:
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size()) return false;
        if(A == "") return false;
        int i = 0, j = A.size()-1;
        while(i < A.size() && A[i] == B[i]) i++;
        while(j >= 0 && A[j] == B[j]) j--;
        if(i == j) return false;
        else if(i < j){
            swap(A[i], A[j]);
            return A == B;
        }
        else{
            set<char> s;
            for(auto c: A){
                if(s.find(c) != s.end()) return true;
                s.insert(c);
            }
            return false;
        }
    }
};