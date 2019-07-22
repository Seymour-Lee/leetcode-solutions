class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int result = 0;
        vector<bool> visited(nums.size(), false);
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == false){
                set<int> st{};
                int cur = i;
                while(st.find(nums[cur]) == st.end()){
                    visited[cur] = true;
                    st.insert(nums[cur]);
                    cur = nums[cur];
                    
                }
                result = max(result, (int)st.size());
            }
        }
        return result;
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        vector<bool> visited(nums.size(), false);
        for(int i = 0; i < nums.size(); i++) if(visited[i] == false){
            unordered_set<int> seen = {};
            seen.insert(nums[i]);
            visited[i] = true;
            int j = nums[i];
            while(seen.find(nums[j]) == seen.end()){
                seen.insert(nums[j]);
                visited[j] = true;
                j = nums[j];
            }
            ans = max(ans, (int)seen.size());
        }
        return ans;
    }
};

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        vector<bool> seen(nums.size(), false);
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) if(seen[i] == false) dfs(nums, i, seen, ans, 0);
        return ans;
    }
    
private:
    void dfs(vector<int>& nums, int i, vector<bool> &seen, int &ans, int counter){
        if(seen[i]) return;
        ans = max(ans, ++counter);
        seen[i] = true;
        dfs(nums, nums[i], seen, ans, counter);
    }
};