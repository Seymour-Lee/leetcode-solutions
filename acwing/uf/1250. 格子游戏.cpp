#include <iostream>
#include <vector>

using namespace std;

vector<int> p;

int f(int x){
    if(p[x] == -1) return x;
    return p[x] = f(p[x]);
}

bool u(int x, int y){
    int px = f(x), py = f(y);
    if(px != py){
        p[px] = py;
        return true;
    }
    return false;
}

int main(){
    int n, m;
    cin >> n >> m;
    p = vector<int>(210*210, -1);
    for(int i = 0; i <= m; i++){
        if(i == m){
            cout<<"draw";
            break;
        }
        int x1, y1, x2, y2;
        char c;
        cin >> x1 >> y1 >> c;
        x1--, y1--;
        // cout<<x1<<" "<<y1<<" "<<c<<endl;
        if(c == 'D') x2 = x1+1, y2 = y1;
        if(c == 'R') x2 = x1, y2 = y1+1;
        int pos1 = x1*210+y1, pos2 = x2*210+y2;
        if(u(pos1, pos2) == false){
            cout<<i+1;
            break;
        }
    }
    return 0;
}