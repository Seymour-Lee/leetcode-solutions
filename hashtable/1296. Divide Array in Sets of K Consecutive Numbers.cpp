class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        // unordered_map<int, int> a2l;
        // for(auto num: nums){
        //     if(a2l.find(num-1) != a2l.end()){
        //         a2l[]
        //     }
        //     else{
        //         a2l[num] = 1;
        //     }
        // }
        map<int, int> a2t;
        for(auto num: nums) a2t[num]++;
        while(a2t.size()){
            int t = k;
            int wanted = a2t.begin()->first;
            // cout<<wanted<<endl;
            while(t--){
                if(a2t[wanted] == 0) return false;
                a2t[wanted]--;
                if(a2t[wanted] == 0) a2t.erase(wanted);
                wanted++;
            }
        }
        return true;
    }
};