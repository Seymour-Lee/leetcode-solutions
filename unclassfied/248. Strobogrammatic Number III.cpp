class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        if (!compare(low, high)) return 0;
        int ans = dfs(low, high, "", 0);
        ans = dfs(low, high, "0", ans);
        ans = dfs(low, high, "1", ans);
        ans = dfs(low, high, "8", ans);
        return ans;
    }
    
private:
    vector<pair<char, char>> nums = { { '0', '0' }, { '1', '1' }, { '6', '9' }, { '8', '8' }, { '9', '6' } };
    
    bool compare(string a, string b){
        if(a.size() != b.size()) return a.size() < b.size();
        return a <= b;
    }
    
    int dfs(string low, string high, string cur, int ans){
        if(high.size() < cur.size()) return ans;
        if (compare(low, cur) && compare(cur, high)) 
            if (cur.size() == 1 || cur.size() > 1 && cur.front() != '0')
                ans++;
        for (auto iter = nums.begin(); iter != nums.end(); ++iter) 
            ans = dfs(low, high, string(1, iter->first) + cur + string(1, iter->second), ans);
        return ans;
    }
};