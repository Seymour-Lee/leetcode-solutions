class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        set<int> appeared;
        for(auto num: nums){
            if(appeared.find(num) == appeared.end()){
                appeared.insert(num);
            }
            else{
                result.push_back(num);
            }
        }
        return result;
    }
};