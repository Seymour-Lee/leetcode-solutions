class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        if((long)lower > (long)upper) return {};
        if(nums.size() == 0) return lower == upper? vector<string>{to_string(lower)}
                                    : vector<string>{to_string(lower)+"->"+to_string(upper)};
        vector<string> ans;
        if(nums[0] != lower){
            if(nums[0]-lower == 1) ans.push_back(to_string(lower));
            else ans.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
        for(int i = 0; i < nums.size()-1; i++){
            if((long)nums[i+1]-nums[i] == 2) ans.push_back(to_string(nums[i]+1));
            else if((long)nums[i+1]-nums[i] > 2) 
                ans.push_back(to_string(nums[i]+1)+"->"+to_string(nums[i+1]-1));
        }
        if(nums.back() != upper){
            if(upper-nums.back() == 1) ans.push_back(to_string(upper));
            else ans.push_back(to_string(nums.back()+1)+"->"+to_string(upper));
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        vector<long> as(nums.begin(), nums.end());
        as.push_back((long)upper+1);
        long prev = (long)lower-1;
        for(int i = 0; i < as.size(); prev = as[i++]){
            string str = gen(prev+1, as[i]-1);
            if(str.size()) ans.push_back(str);
        }
        return ans;
    }
    
private:
    string gen(long a, long b){
        if(a > b) return "";
        if(a == b) return to_string(a);
        return to_string(a) + "->" + to_string(b);
    }
};