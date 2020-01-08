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

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> g[i][j];
    for(int i = 1; i < n; i++) g[i][0] += g[i-1][0], g[0][i] += g[0][i-1];
    for(int i = 1; i < n; i++) for(int j = 1; j < n; j++) g[i][j] += min(g[i-1][j], g[i][j-1]);
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++) cout<<g[i][j]<<" ";
    //     cout<<endl;
    // }
    cout<<g[n-1][n-1]<<endl;
    return 0;
}
