class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        int n = A.size();
        int ones = 0;
        for(auto a: A) ones += a;
        if(ones % 3 != 0) return {-1, -1};
        int t = ones / 3;
        if(t == 0) return {0, n-1};
        int i1 = -1, j1 = -1, i2 = -1, j2 = -1, i3 = -1, j3 = -1;
        for(int i = 0, su = 0; i < n; i++){
            if(A[i] == 1){
                su += 1;
                if(su == 1) i1 = i;
                if(su == t) j1 = i;
                if(su == t+1) i2 = i;
                if(su == 2*t) j2 = i;
                if(su == 2*t+1) i3 = i;
                if(su == 3*t) j3 = i;
            }
        }
        
        vector<int> p1(A.begin()+i1, A.begin()+j1+1);
        vector<int> p2(A.begin()+i2, A.begin()+j2+1);
        vector<int> p3(A.begin()+i3, A.begin()+j3+1);
        
        if(p1 != p2 || p2 != p3) return {-1, -1};
        
        int x = i2-j1-1;
        int y = i3-j2-1;
        int z = A.size()-j3-1;
        if(x < z || y < z) return {-1, -1};
        return {j1+z, j2+z+1};
    }
};

// TLE
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        string str = "";
        for(auto a: A) str += (a == 1? '1': '0');
        for(int i = 0; i < A.size()-2; i++){
            for(int j = i + 2; j < A.size(); j++){
                if(valid(str, i, j)) return {i, j};
            }
        }
        return {-1, -1};
    }
    
private:
    bool valid(string str, int i, int j){
        string a = deleteZeros(str.substr(0, i+1));
        string b = deleteZeros(str.substr(i+1, j-i-1));
        string c = deleteZeros(str.substr(j));
        return a == b && b == c;
    }
    
    string deleteZeros(string str){
        int i = 0;
        while(i < str.size() && str[i] == '0') i++;
        return str.substr(i);
    }
};