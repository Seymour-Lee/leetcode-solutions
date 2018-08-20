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