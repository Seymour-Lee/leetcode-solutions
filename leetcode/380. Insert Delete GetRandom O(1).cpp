class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        //srand(time(0));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(val2idx.find(val) != val2idx.end()) return false;
        nums.push_back(val);
        val2idx[val] = nums.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(val2idx.find(val) == val2idx.end()) return false;
        val2idx[nums.back()] = val2idx[val];
        nums[val2idx[val]] = nums.back();
        nums.pop_back();
        val2idx.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % nums.size();
        return nums[r];
    }
    
private:
    vector<int> nums;
    unordered_map<int, int> val2idx;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */