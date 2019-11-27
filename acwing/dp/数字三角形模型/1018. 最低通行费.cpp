#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> g(N, vector<int>(N));
    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++){
        cin >> g[i][j];
        int minval = min(i-1 >= 0? g[i-1][j]: INT_MAX, j-1 >= 0? g[i][j-1]: INT_MAX);
        g[i][j] += minval == INT_MAX? 0: minval;
    }
    // for(int i = 0; i < N; i++){
    //     for(int j = 0; j < N; j++){
    //         cout<<g[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<g[N-1][N-1];
    return 0;
}
