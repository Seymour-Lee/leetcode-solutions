class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans = val2idxs.find(val) == val2idxs.end();
        val2idxs[val].push_back(nums.size());
        nums.push_back({val, val2idxs[val].size()-1});
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(val2idxs.find(val) == val2idxs.end()) return false;
        auto back = nums.back();
        val2idxs[back.first][back.second] = val2idxs[val].back();
        nums[val2idxs[val].back()] = back;
        val2idxs[val].pop_back();
        if(val2idxs[val].empty()) val2idxs.erase(val);
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
    
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> val2idxs;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */