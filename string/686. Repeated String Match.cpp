class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A.size() == 0) return -1;
        int result;
        string str = A;
        for(result = 1; str.size() < B.size(); result++) str = str + A;
        if(str.find(B) != string::npos) return result;
        str = str + A;
        if(str.find(B) != string::npos) return result + 1;
        return  -1;
    }
};

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if(A.size() == 0) return -1;
        int result;
        string str = A;
        for(result = 1; str.size() < B.size(); result++) str = str + A;
        if(str.find(B) != string::npos) return result;
        str = str + A;
        if(str.find(B) != string::npos) return result + 1;
        return  -1;
    }
};