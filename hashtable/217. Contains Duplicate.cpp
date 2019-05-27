class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto num: nums){
            if(s.find(num) != s.end()) return true;
            s.insert(num);
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(auto num: nums){
            if(seen.find(num) != seen.end()) return true;
            seen.insert(num);
        }
        return false;
    }
};