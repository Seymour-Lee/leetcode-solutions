// MLE
class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        unordered_set<int> nums;
        for(int i = 0; i < N; i++) nums.insert(i);
        for(auto b: blacklist) nums.erase(b);
        whitelist = vector<int>(nums.begin(), nums.end());
    }
    
    int pick() {
        return whitelist[rand() % whitelist.size()];
    }
    
private:
    vector<int> whitelist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

// TLE
class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        n = N;
        sort(blacklist.begin(), blacklist.end());
        b = blacklist;
    }
    
    int pick() {
        int k = rand() % (n - b.size());
        int l = 0, r = b.size()-1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(b[m]-m > k) r = m-1;
            else l = m;
        }
        return l == r && b[l]-l <= k? k+l+1: k; 
    }
    
private:
    int n;
    vector<int> b;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        wlen = N - blacklist.size();
        unordered_set<int> whitelist;
        for(int i = wlen; i < N; i++) whitelist.insert(i);
        for(auto b: blacklist) whitelist.erase(b);
        auto itor = whitelist.begin();
        for(auto x: blacklist){
            if(x < wlen)
                idx2white[x] = *itor++;
        }
    }
    
    int pick() {
        int k = rand() % wlen;
        return idx2white.find(k) != idx2white.end()? idx2white[k]: k;
    }
    
private:
    unordered_map<int, int> idx2white;
    int wlen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */

class Solution {
public:
    Solution(int N, vector<int> blacklist) {
        wlen = N - blacklist.size();
        unordered_set<int> whitelist;
        for(int i = wlen; i < N; i++) whitelist.insert(i);
        for(auto b: blacklist) whitelist.erase(b);
        auto itor = whitelist.begin();
        for(auto x: blacklist){
            if(x < wlen)
                idx2white[x] = *itor++;
        }
    }
    
    int pick() {
        int k = rand() % wlen;
        return idx2white.find(k) != idx2white.end()? idx2white[k]: k;
    }
    
private:
    unordered_map<int, int> idx2white;
    int wlen;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */