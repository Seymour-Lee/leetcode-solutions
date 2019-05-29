class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        hash = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
    
private:
    vector<bool> hash;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */

class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        arr[key] = true;
    }
    
    void remove(int key) {
        arr[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return arr[key];
    }
    
private:
    vector<bool> arr = vector<bool>(1000001, false);
    
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */