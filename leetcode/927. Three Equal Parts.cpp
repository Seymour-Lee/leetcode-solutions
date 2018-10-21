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