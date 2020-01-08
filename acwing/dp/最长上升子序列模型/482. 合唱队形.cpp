#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> l(n, 1), r(n, 1);
    for(int j = 0; j < n; j++) for(int i = 0; i < j; i++) if(nums[i] < nums[j]) l[j] = max(l[j], l[i]+1);
    for(int i = n-1; i >= 0; i--) for(int j = n-1; i < j; j--) if(nums[i] > nums[j]) r[i] = max(r[i], r[j]+1);
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, l[i]+r[i]-1);
    cout<<n-ans;
    return 0;
}