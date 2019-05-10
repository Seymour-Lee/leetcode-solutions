class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xc = counter(board, 'X'), oc = counter(board, 'O');
        bool xw = win(board, 'X'), ow = win(board, 'O');
        if(xw && ow) return false;
        if(xw) return xc == oc+1;
        if(ow) return oc == xc;
        return xc == oc+1 || xc == oc;
    }
    
private:
    int counter(vector<string> &b, char c){
        int res = 0;
        for(auto s: b){
            res += count(s.begin(), s.end(), c);
        }
        return res;
    }
    
    bool win(vector<string> &b, char c){
        for(int i = 0; i < 3; i++){
            if(b[i][0] == c && b[i][1] == c && b[i][2] == c) return true;
        }
        for(int i = 0; i < 3; i++){
            if(b[0][i] == c && b[1][i] == c && b[2][i] == c) return true;
        }
        return (b[0][0] == c && b[1][1] == c && b[2][2] == c) 
            || (b[2][0] == c && b[1][1] == c && b[0][2] == c);
    }
};