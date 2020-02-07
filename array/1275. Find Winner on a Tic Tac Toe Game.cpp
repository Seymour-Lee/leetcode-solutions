class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int p = 1;
        for(auto m: moves){
            int i = m[0], j = m[1];
            if(p == 1){
                g[i][j] = 'X';
                if(va()) return "A";
            }
            else{
                g[i][j] = 'O';
                if(vb()) return "B";
            }
            p = -p;
        }
        return moves.size() < 9? "Pending": "Draw";
    }
    
private:
    vector<string> g = vector<string>(3, "   ");
    
    bool va(){
        for(auto r: g) if(r == "XXX") return true;
        for(int j = 0; j < 3; j++){
            if(g[0][j] == 'X' && g[1][j] == 'X' && g[2][j] == 'X') return true;
        }
        return g[0][0] == 'X' && g[1][1] == 'X' && g[2][2] == 'X' || 
               g[0][2] == 'X' && g[1][1] == 'X' && g[2][0] == 'X';
    }
    
    bool vb(){
        for(auto r: g) if(r == "OOO") return true;
        for(int j = 0; j < 3; j++){
            if(g[0][j] == 'O' && g[1][j] == 'O' && g[2][j] == 'O') return true;
        }
        return g[0][0] == 'O' && g[1][1] == 'O' && g[2][2] == 'O' || 
               g[0][2] == 'O' && g[1][1] == 'O' && g[2][0] == 'O';
    }
};