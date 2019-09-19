class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        for(int i = 0; i < maxNumbers; i++) unused.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(unused.size() == 0) return -1;
        int ans = *unused.begin();
        unused.erase(ans);
        used.insert(ans);
        return ans;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return unused.find(number) != unused.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        unused.insert(number);
        used.erase(number);
    }
    
private:
    set<int> unused;
    set<int> used;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        upper = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(a.size()){
            int ans = *a.begin();
            a.erase(ans);
            return ans;
        }
        return cur >= upper? -1: cur++;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return number >= cur || a.find(number) != a.end();
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if(number >= cur) return;
        a.insert(number);
    }
    
private:
    int cur = 0;
    int upper;
    
    unordered_set<int> a;
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */