class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int maxval = 0;
        int dep = 0;
        vector<int> deps(seq.size(), 0);
        for(int i = 0; i < seq.size(); i++){
            if(seq[i] == '(') dep++;
            deps[i] = dep;
            maxval = max(maxval, dep);
            if(seq[i] == ')') dep--;
        }
        vector<int> ans;
        for(auto d: deps){
            if(d <= maxval/2) ans.push_back(0);
            else ans.push_back(1);
        }
        return ans;
    }
};