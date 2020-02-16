class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        set<int> st(nums.begin(), nums.end());
        int prev = INT_MIN;
        int cur = 0;
        for(auto e: st){
            cur = e-1 == prev? cur+1: 1;
            prev = e;
            ans = max(ans, cur);
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        for(auto num: nums){
            if(p.find(num) != p.end()) continue;
            p[num] = INT_MAX;
            if(p.find(num-1) != p.end()) u(num, num-1);
            if(p.find(num+1) != p.end()) u(num, num+1);
        }
        unordered_map<int, int> p2num;
        for(auto v: p){
            p2num[f(v.first)]++;
        }
        int ans = 0;
        for(auto v: p2num) ans = max(ans, v.second);
        return ans;
    }
    
private:
    unordered_map<int, int> p;
    
    int f(int x){
        if(p[x] == INT_MAX) return x;
        return f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int ans = 1;
        set<int> as(nums.begin(), nums.end());
        int prev = INT_MIN;
        int counter = 1;
        for(auto e: as){
            if(prev+1 == e) counter++, ans = max(ans, counter);
            else counter = 1;
            prev = e;
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        set<int> as(nums.begin(), nums.end());
        int prev = INT_MIN;
        int cur = 0;
        for(auto a: as){
            if(a == prev+1) cur++;
            else cur = 1;
            prev = a;
            ans = max(ans, cur);
        }
        return ans;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        set<int> as(nums.begin(), nums.end());
        int prev = INT_MIN;
        int cur = 0;
        for(auto a: as){
            if(a == prev+1) cur++;
            else cur = 1;
            prev = a;
            ans = max(ans, cur);
        }
        return ans;
    }
};