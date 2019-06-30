class Solution {
public:
    bool canSortDoubled(vector<int>& A) {
        multiset<int> nums(A.begin(), A.end());
        while(nums.empty() == false){
            auto b = nums.begin();
            auto lowest = *b;
            nums.erase(b);
            if(lowest < 0){
                if(lowest % 2 == 1) return false;
                auto itor = nums.find(lowest/2);
                if(itor == nums.end()) return false;
                nums.erase(itor);
            }
            else{
                auto itor = nums.find(2*lowest);
                if(itor == nums.end()) return false;
                nums.erase(itor);
            }
        }
        return true;
    }
};  

class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        sort(A.begin(), A.end());
        unordered_map<int, int> a2t;
        for(auto a: A) a2t[a]++;
        for(auto a: A) if(a2t[a] && a2t[a*2]) a2t[a]--, a2t[a*2]--;
        for(auto p: a2t) if(p.second) return false;
        return true;
    }
};