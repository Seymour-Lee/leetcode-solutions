#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int K;
    cin >> K;
    while(K--){
        int n;
        cin >> n;
        vector<int> h(n), a(n), d(n);
        for(int j = 0; j < n; j++){
            cin >> h[j];
            a[j] = d[j] = 1;
            for(int i = 0; i < j; i++){
                if(h[i] < h[j]) a[j] = max(a[j], a[i]+1);
                if(h[i] > h[j]) d[j] = max(d[j], d[i]+1);
            }
        }
        cout<<max(*max_element(a.begin(), a.end()), *max_element(d.begin(), d.end()))<<endl;
    }
    return 0;
}