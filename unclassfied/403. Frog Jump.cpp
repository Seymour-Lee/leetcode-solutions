class Solution {
public:
    bool canCross(vector<int>& stones) {
        return dp(stones, 0, 0);
    }
    
private:
    unordered_map<int, bool> memo;
    bool dp(vector<int>& stones, int pos, int len){
        if(pos >= stones.size()-1) return true;
        int key = pos | len << 11;
        if(memo.find(key) != memo.end()) return memo[key];
        for(int i = pos+1; i < stones.size(); i++){
            int dist = stones[i] - stones[pos];
            if(dist < len-1) continue;
            if(dist > len+1) return memo[key] = false;
            if(dp(stones, i, dist)) return memo[key] = true;
        }
        return memo[key] = false;
    }
};