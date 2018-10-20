class Solution {
public:
    vector<int> solution(vector<int> stores, vector<int> houses) {
        int m = stores.size(), n = houses.size();
        vector<int> nearest(n, -1);
        set<int> sortedStores(stores.begin(), stores.end());
        stores = vector<int>(sortedStores.begin(), sortedStores.end());
        for(int i = 0; i < houses.size(); i++){
            nearest[i] = binary(stores, houses[i]);
//             auto itupper = sortedStores.upper_bound(houses[i]);
//             auto itlower = prev(itupper);
//             // cout<<houses[i]<<" "<<*itlower<<" "<<*itupper<<endl;
//             // if(itlower == sortedStores.end()) cout<<"itlower is end()"<<endl;
//             // if(itupper == sortedStores.end()) cout<<"itupper is end()"<<endl;
            
//             if(itupper == sortedStores.end()) nearest[i] = *itlower;
//             else if(itupper == sortedStores.begin()) nearest[i] = *itupper;
//             else{
//                 nearest[i] = houses[i]-(*itlower) <= (*itupper)-houses[i]? (*itlower): (*itupper);
//             }
        }
        return nearest;
    }
    
private:
    int binary(vector<int> stores, int target){
        if(target <= stores.front()) return stores.front();
        if(target >= stores.back()) return stores.back();
        int l = 0, r = stores.size()-1;
        while(l <= r){
            int m = l + (r - l) / 2;
            if(stores[m] <= target && target <= stores[m+1]){
                return target-stores[m] <= stores[m+1]-target? stores[m]: stores[m+1];
            }
            else if(target < stores[m]){
                r = m;
            }
            else if(stores[m] < target){
                l = m;
            }
            else{
                cout<<"some bugs raise up"<<endl;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> stores = {200, 5, 8, 8, 8, 5, 9, 20, 100, 0};
    vector<int> houses = {2, 6, 12, 18, 22, 8, 8, 2, 0};
    auto ans = sol.solution(stores, houses);
    for(auto a: ans) cout<<a<<" ";
    return 0;
}