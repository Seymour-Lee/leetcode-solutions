class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        set<int> s;
        for(auto num: nums1) s.insert(num);
        for(auto num: nums2){
            set<int>::iterator itor = s.find(num);
            if(itor != s.end()){
                result.push_back(num);
                s.erase(itor);
            }
        }
        return result;
    }
};