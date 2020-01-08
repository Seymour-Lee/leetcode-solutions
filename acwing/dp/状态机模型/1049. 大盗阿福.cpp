#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        int rob = nums[0], no = 0;
        for(int i = 1; i < n; i++){
            int next_rob = no + nums[i];
            int next_not = max(rob, no);
            rob = next_rob, no = next_not;
        }
        cout<<max(rob, no)<<endl;
    }
    return 0;
}