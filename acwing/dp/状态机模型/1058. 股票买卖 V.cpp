#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int in = -nums[0], ou = 0, co = 0;
    for(int i = 1; i < n; i++){
        int next_in = max(in, ou-nums[i]);
        int next_ou = max(co, ou);
        int next_co = in+nums[i];
        in = next_in, ou = next_ou, co = next_co;
    }
    cout<< max(ou, co);
    return 0;
}
