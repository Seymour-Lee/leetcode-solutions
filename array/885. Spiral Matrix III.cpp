class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int N = R*C;
        vector<vector<int>> ans;               
        auto put = [&](int r, int c) { 
            if(0 <= r && r < R && 0 <= c && c < C) ans.push_back({r, c});          
        };
        int dis = 1;
        put(r0, c0);              
        while (ans.size() != N){
            for(int r = r0-dis+1; r <= r0+dis; r++) put(r, c0+dis);            
            for(int c = c0+dis-1; c >= c0-dis; c--) put(r0+dis, c);
            for(int r = r0+dis-1; r >= r0-dis; r--) put(r, c0-dis);    
            for(int c = c0-dis+1; c <= c0+dis; c++) put(r0-dis, c);    
            dis++;
        }
        return ans;
    }
};