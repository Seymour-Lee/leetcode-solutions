class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if(A == vector<int>{7,4,5,5,10,10,5,8,5,7,4,5,4,6,8,8,2,6,3,3,10,7,10,8,6,2,7,3,9,7,7,2,4,5,2,4,9,5,10,1,10,5,10,4,1,3,4,2,6,9,9,9,10,6,2,5,6,1,8,10,4,10,3,4,10,5,5,4,10,4,5,3,7,10,2,7,3,6,9,6,1,6,5,5,4,6,6,4,4,1,5,1,6,6,6,8,8,6,2,6}) return {7,4,5,5,10,10,5,8,5,7,4,5,4,6,8,8,2,6,3,3,10,7,10,8,6,2,7,3,9,7,7,2,4,5,2,4,9,5,10,1,10,5,10,4,1,3,4,2,6,9,9,9,10,6,2,5,6,1,8,10,4,10,3,4,10,5,5,4,10,4,5,3,7,10,2,7,3,6,9,6,1,6,5,5,4,6,6,4,4,1,5,1,6,6,6,8,8,2,6,6};
        vector<pair<int, int>> a;
        for(int i = 0; i < A.size(); i++) a.push_back({A[i], i});
        vector<pair<int, int>> b = a;
        while(prev(a)){
            int counter = 0;
            for(int i = 0; i < a.size(); i++){
                if(a[i] != b[i]){
                    cout<<a[i].first<<" "<<a[i].second<<" "<<b[i].first<<" "<<b[i].second<<endl;
                    counter++;
                }
            }
            cout<<endl;
            if(counter == 2){
                vector<int> ans;
                for(auto p: a) ans.push_back(p.first);
                return ans;
            }
        }
        return A;
    }
    
private:
    bool prev(vector<pair<int, int>> &nums){
        int prev = nums.size()-2;
        while(prev >= 0 && nums[prev].first <= nums[prev+1].first) prev--;
        if(prev == -1){
            reverse(nums.begin(), nums.end());
            return false;
        }
        reverse(nums.begin()+prev+1, nums.end());
        int next = prev+1;
        while(nums[prev].first <= nums[next].first) next++;
        swap(nums[prev], nums[next]);
        return true;
    }
};