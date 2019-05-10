// TLE, cause the test case has too many add operations
class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        for(auto num: nums) sums.insert(number + num);
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        return sums.find(value) != sums.end();
    }
    
private:
    unordered_set<int> sums;
    vector<int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        nums.push_back(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        unordered_map<int, int> val2idx;
        for(int i = 0; i < nums.size(); i++){
            int target = value - nums[i];
            if(val2idx.find(target) != val2idx.end()) return true;
            val2idx[nums[i]] = i;
        }
        return false;
    }
    
private:
    vector<int> nums;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */