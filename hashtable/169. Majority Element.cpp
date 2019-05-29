class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        map<int, int> num_to_times;
        for(auto num: nums){
            if(num_to_times.find(num) != num_to_times.end()){
                num_to_times[num]++;
            }
            else{
                num_to_times[num] = 1;
            }
        }
        int half = nums.size() / 2;
        for(map<int, int>::iterator itor = num_to_times.begin(); itor != num_to_times.end(); itor++){
            if(itor->second > half) return itor->first;
        }
        return 0;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = nums[0];
        int counter = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == ans) counter++;
            else{
                counter--;
                if(counter == 0){
                    ans = nums[i];
                    counter++;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> n2t;
        for(auto num: nums) n2t[num]++;
        for(auto p: n2t) if(p.second > nums.size()/2) return p.first;
        return 0;
    }
};