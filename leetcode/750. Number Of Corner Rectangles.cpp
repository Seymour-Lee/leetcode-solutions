class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        map<int, int> count;
        int ans = 0;
        for(auto row: grid){
            for(int c1 = 0; c1 < row.size(); c1++) if(row[c1] == 1){
                    for(int c2 = c1+1; c2 < row.size(); c2++) if(row[c2] == 1){
                        int pos = c1*200+c2; // pos signature
                        int c = count[pos];
                        ans += c;
                        count[pos] = c+1;
                }
            }
        }
        return ans;
    }
};