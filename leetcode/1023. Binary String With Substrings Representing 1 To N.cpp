class Solution {
public:
    bool queryString(string S, int N) {
        int low = N/2+1;
        string str = get(low);
        for(int i = low; i <= N; i++){
            if(S.find(str) == string::npos) return false;
            str = next(str);
        }
        return true;
    }
    
private:
    string next(string str){
        int c = 0;
        for(int i = str.size()-1; i >= 0; i--){
            if(str[i] == '0'){
                str[i] = '1';
                c = 0;
                break;
            }
            else{
                str[i] = '0';
                c = 1;
            }
        }
        if(c == 1) str = "1"+str;
        return str;
    }
    
    string get(int n){
        string r;
        while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
        return r;
    }
};