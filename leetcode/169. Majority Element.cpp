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