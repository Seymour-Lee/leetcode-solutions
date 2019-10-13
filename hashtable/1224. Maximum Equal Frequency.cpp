class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int ans = 1;
        map<int, unordered_set<int>> f2a;
        unordered_map<int, int> a2f;
        for(int i = 0; i < nums.size(); i++){
            int a = nums[i];
            if(a2f.find(a) != a2f.end()){
                int count = a2f[a];
                f2a[count].erase(a);
                if(f2a[count].size() == 0) f2a.erase(count);
                f2a[count+1].insert(a);
                a2f[a]++;
            }
            else{
                a2f[a] = 1;
                f2a[1].insert(a);
            }
            if(f2a.size() == 1){
                int f = f2a.begin()->first, size = f2a.begin()->second.size();
                if(f == 1 || size == 1){
                    // cout<<i<<" "<<nums[i]<<" "<<f2a.size()<<endl;
                    ans = i+1;
                }
            }
            if(f2a.size() == 2){
                int f1 = f2a.begin()->first, f2 = next(f2a.begin())->first;
                int size1 = f2a.begin()->second.size(), size2 = next(f2a.begin())->second.size();
                if(f1 == 1 && size1 == 1){
                    // cout<<i<<" "<<nums[i]<<" "<<f2a.size()<<endl;
                    ans = i+1;
                }
                if(f1+1 == f2 && (size2 == 1)){
                    // cout<<i<<" "<<nums[i]<<" "<<f2a.size()<<endl;
                    ans = i+1;
                }
            }
            // if(f2a.size() == 1 && (f2a.begin()->second.size() == 1 || f2a.begin()->first == 1) || 
            //    // (f2a.size() == 2 && )){
            //    (f2a.size() == 2 && (f2a.begin()->first == 1 && f2a.begin()->second.size() == 1 || 
            //                         (f2a.begin()->second.size() == 1 || next(f2a.begin())->second.size() == 1) && abs(f2a.begin()->first - next(f2a.begin())->first) == 1))){
            //     // cout<<i<<" "<<nums[i]<<" "<<f2a.size()<<endl;
            //     ans = i+1;
            // }
        }
        return ans;
    }
};

// [1,2] 2
// [1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,42,21,45,27,78,39,78,24,47,60,22,33,45,18,56,91,93,66,79,65,43,7,57,63,74,25,11,14,100,95,19,3,22,18,94,52,91,33,95,16,93,63,65,8,88,51,47,7,51,77,36,48,89,72,81,75,13,69,9,31,16,38,34,76,7,82,10,90,64,28,22,99,40,88,27,94,85,43,75,95,86,82,46,9,74,67,51,93,97,35,2,49] 7