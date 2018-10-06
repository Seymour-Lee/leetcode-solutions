class Solution {
public:
    int pathSum(vector<int>& nums) {
        int ans = 0;
        map<int, int> pos2val;
        for(auto num: nums) pos2val[num/10] = num%10;
        dfs(nums[0]/10, 0, ans, pos2val);
        return ans;
    }
    
private:
    void dfs(int node, int sum, int &ans, map<int, int> &pos2val){
        if(pos2val.find(node) == pos2val.end()) return;
        sum += pos2val[node];
        int depth = node/10, pos = node%10;
        int left = (depth+1)*10 + 2*pos - 1;
        int right = left+1;
        if(pos2val.find(left) == pos2val.end() && pos2val.find(right) == pos2val.end()){
            ans += sum;
        }
        else{
            dfs(left, sum, ans, pos2val);
            dfs(right, sum, ans, pos2val);
        }
    }
};