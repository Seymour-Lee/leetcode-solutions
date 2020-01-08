#include <iostream>
#include <vector>

// topleft -> bottomright and bottomright ->topleft == topleft -> bottomright and topleft -> bottomright
// two path can't cross each other
// [i1][j1][i2][j2]

using namespace std;

const int M = 55;
const int N = 55;

int g[M][N];
int dp[M+N][M][N];

int main(){
    int m, n;
    cin >> m >> n;
    for(int i = 1; i <= m; i++) for(int j = 1; j <= n; j++) cin >> g[i][j];
    for(int k = 2; k <= m+n; k++){
        for(int i1 = 1; i1 <= m; i1++){
            for(int i2 = i1+1; i2 <= m; i2++){ // i1 < i2
                int j1 = k-i1, j2 = k-i2;
                if(1 <= j1 && j1 <= n && 1 <= j2 && j2 <= n){
                    int t = g[i1][j1] + g[i2][j2];
                    int &x = dp[k][i1][i2];
                    x = max(x, dp[k-1][i1][i2]+t);
                    x = max(x, dp[k-1][i1-1][i2]+t);
                    x = max(x, dp[k-1][i1][i2-1]+t);
                    x = max(x, dp[k-1][i1-1][i2-1]+t);
                    // cout<<k<<" "<<i1<<" "<<i2<<" "<<x<<endl;
                }
            }
        }
    }
    cout<<dp[m+n-1][m-1][m];
    return 0;
}