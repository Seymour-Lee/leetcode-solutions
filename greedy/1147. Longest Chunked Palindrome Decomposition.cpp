class Solution {
public:
    int longestDecomposition(string text) {
        // if(text == "elvtoelvto") return 2;
        return dfs(text, 0, 0, text);
    }
    
private:
    int dfs(string cur, int counter, int len, string str){
        if(cur.size() == 0) return counter;
        if(cur.size() <= 1){
            if(counter != 0 && str.size()-len <= 1) return counter+1;
            else return 1;
        }
        // cout<<cur<<" "<<str<<endl;
        int n = cur.size();
        for(int i = 0; i < n/2; i++){
            if(cur.substr(0, i+1) == cur.substr(n-i-1)){
                // if(i+1 == n/2) return counter+2;
                return dfs(cur.substr(i+1, n-2*i-2), counter+2, len+(i+1)*2, str);
            }
        }
        // cout<<counter<<endl;
        return counter+1;
    }
};

