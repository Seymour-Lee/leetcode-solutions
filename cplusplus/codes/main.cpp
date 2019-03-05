#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;


long sum3(vector<int> a, int target){
    if(a.size() <= 2) return 0;
    long ans = 0;
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size()-2; i++){
        int sum = target - a[i];
        if(sum < 0) break;
        int l = i+1, r = a.size()-1;
        while(l < r){
            if(a[l] + a[r] == sum){
                if(a[l] == a[r]){
                    ans += (long)(r-l+1) * (r-l) / 2;
                    break;
                }
                else{
                    long lcount = 1, rcount = 1;
                    while(a[l] == a[l+1]) l++, lcount++;
                    while(a[r] == a[r-1]) r--, rcount++;
                    ans += lcount * rcount;
                    l++, r--;
                }
            }
            else if(a[l] + a[r] < sum) l++;
            else r--;
        }
    }

    return ans;
}




int main(){
    // vector<int> a = {4, 5, 10, 7, 3, 4, 7, 4, 1, 8};
    // auto ans1 = sum3(a, 20); // ans = 4
    // cout<<ans1<<endl;
    // auto ans2 = sum3(vector<int>{1, 2, 3, 3, 3, 3, 3, 3, 4}, 7); // ans = 16
    // cout<<ans2<<endl;
    // auto ans3 = sum3(vector<int>{-1, 0, 1, 2, -1, -4}, 0);
    // cout<<ans3<<endl;
    return 0;
}