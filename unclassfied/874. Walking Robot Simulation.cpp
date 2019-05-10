class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int x = 0, y = 0, di = 0;
        set<pair<int ,int>> s;
        for(auto ob: obstacles) s.insert(pair<int, int>(ob[0], ob[1]));
        int result = 0;
        for(auto cmd: commands){
            if(cmd == -2){
                di = (di + 3) % 4;
            }
            else if(cmd == -1){
                di = (di + 1) % 4;
            }
            else{
                for(int i = 0; i < cmd; i++){
                    int nx = x + dx[di];
                    int ny = y + dy[di];
                    if(s.find(pair<int, int>(nx, ny)) == s.end()){
                        x = nx;
                        y = ny;
                        result = max(result, x*x + y*y);
                    }
                }
            }
        }
        return result;
    }
};