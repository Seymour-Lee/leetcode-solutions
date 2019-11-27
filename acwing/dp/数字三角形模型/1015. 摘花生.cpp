#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin>>T;
    while(T--){
        int r, c;
        cin >> r >> c;
        vector<vector<int>> g = vector<vector<int>>(r, vector<int>(c));
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) cin>>g[i][j];
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) g[i][j] += max(i-1 >= 0? g[i-1][j]: 0, j-1 >= 0? g[i][j-1]: 0);
        cout<<g.back().back()<<endl;
    }
    return 0;
}