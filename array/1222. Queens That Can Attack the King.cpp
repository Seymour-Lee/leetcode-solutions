class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& k) {
        vector<vector<int>> ans;
        vector<vector<int>> aa(8, vector<int>(2, -1));
        for(auto q: queens) if(q != k){
            if(k[0]-q[0] == k[1]-q[1]){
                if(k[0] > q[0]){ // 0
                    if(aa[0][0] == -1 || (abs(k[0]-q[0]) < abs(k[0]-aa[0][0]))) aa[0] = q;
                }
                else{ // 7
                    if(aa[7][0] == -1 || (abs(q[0]-k[0]) < abs(aa[7][0]-k[0]))) aa[7] = q;
                }
            }
            else if(k[0]+k[1] == q[0]+q[1]){
                if(k[0] > q[0]){ // 5
                    if(aa[5][0] == -1 || abs(k[0]-q[0]) < abs(k[0]-aa[5][0])) aa[5] = q;
                }
                else{ // 2
                    if(aa[2][0] == -1 || abs(k[0]-q[0]) < abs(k[0]-aa[2][0])) aa[2] = q;
                }
            }
            else if(k[0] == q[0]){
                if(k[1] > q[1]){ //3
                    if(aa[3][0] == -1 || abs(k[1]-q[1]) < abs(k[1]-aa[3][1])) aa[3] = q;
                }
                else{ // 4
                    if(aa[4][0] == -1 || abs(k[1]-q[1]) < abs(k[1]-aa[4][1])) aa[4] = q;
                }
            }
            else if(k[1] == q[1]){
                if(k[0] > q[0]){ // 1
                    if(aa[1][0] == -1 || abs(k[0]-q[0]) < abs(k[0]-aa[1][0])) aa[1] = q;
                }
                else{ // 6
                    if(aa[6][0] == -1 || abs(k[0]-q[0]) < abs(k[0]-aa[6][0])) aa[6] = q;
                }
            }
        }
        for(auto a: aa) if(a[0] != -1) ans.push_back(a);
        return ans;
    }
};