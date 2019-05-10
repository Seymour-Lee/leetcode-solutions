class Solution {
public:
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int, int> rowc, colc;
        unordered_map<int, int> diag, rdiag;
        set<vector<int>> pos(lamps.begin(), lamps.end());
        for(auto p: lamps){
            int r = p[0], c = p[1];
            rowc[r]++;
            colc[c]++;
            diag[r-c]++;
            rdiag[r+c]++;
        }
        vector<int> ans;
        for(auto q: queries){
            int x = q[0], y = q[1];
            if(rowc[x] > 0 || colc[y] > 0 || diag[x-y] > 0 || rdiag[x+y] > 0) ans.push_back(1);
            else ans.push_back(0);
            for(int r = x-1; r <= x+1; r++) for(int c = y-1; c <= y+1; c++) if(pos.find({r, c}) != pos.end()){
                pos.erase({r, c});
                rowc[r]--;
                colc[c]--;
                diag[r-c]--;
                rdiag[r+c]--;
            }
        }
        return ans;
    }
};