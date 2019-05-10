class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if(tree.size() == 0) return 0;
        int ans = 0;
        int l = 0;
        map<int, int> int2freq;
        for(int r = 0; r < tree.size(); r++){
            int2freq[tree[r]]++;
            while(l <= r && int2freq.size() >= 3){
                int2freq[tree[l]]--;
                if(int2freq[tree[l]] == 0) int2freq.erase(tree[l]);
                l++;
            }
            ans = max(ans, r-l+1);
        }
        return ans;
    }
};