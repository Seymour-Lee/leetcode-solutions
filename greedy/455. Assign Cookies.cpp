class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(g.size() == 0 || s.size() == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        for(int i = 0, j = 0; j < s.size() && i < g.size(); j++){
            if(s[j] >= g[i]){
                result++;
                i++;
            }
        }
        return result;
    }
};

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        int ans = 0;
        while(i < g.size() && j < s.size()){
            if(s[j++] >= g[i]) i++, ans++;
        }
        return ans;
    }
};