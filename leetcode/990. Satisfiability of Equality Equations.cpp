class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> p(26, -1);
        int i = 0, j = equations.size()-1;
        while(i < j){
            if(equations[i][1] == '=') i++;
            else if(equations[j][1] == '!') j--;
            else swap(equations[i++], equations[j--]);
        }
        // for(auto str: equations)cout<<str<<endl;
        for(auto str: equations){
            int a = str[0]-'a', b = str[3]-'a';
            if(str[1] == '!') {
                if(f(p, a) == f(p, b)) return false;
            }
            else u(p, a, b);
        }
        return true;
    }
    
private:
    int f(vector<int> &p, int x){
        if(p[x] == -1) return x;
        return p[x] = f(p, p[x]);
    }
    
    void u(vector<int> &p, int x, int y){
        int px = f(p, x);
        int py = f(p, y);
        if(px != py) p[px] = py;
    }
    
};