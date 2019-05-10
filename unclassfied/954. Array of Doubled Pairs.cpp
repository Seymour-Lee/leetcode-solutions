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