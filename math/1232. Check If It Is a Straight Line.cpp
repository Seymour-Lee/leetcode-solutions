class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        for(int i=1;i<c.size()-1;i++){
            if((c[i][1]-c[0][1])*(c[i+1][0]-c[0][0])!=(c[i+1][1]-c[0][1])*(c[i][0]-c[0][0])) return false;
        }
        return true;
    }
};