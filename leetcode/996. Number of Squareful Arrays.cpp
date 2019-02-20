class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        for(auto a: A) num2times[a]++;
        for(auto i: num2times) for(auto j: num2times){
            int ii = i.first, jj = j.first, ss = sqrt(ii+jj);
            if(ss*ss == ii+jj) x2y[ii].insert(jj);
        }
        for(auto p: num2times) dfs(p.first, A.size()-1);
        return ans;
    }
    
private:
    unordered_map<int, int> num2times;
    unordered_map<int, unordered_set<int>> x2y;
    int ans = 0;
    
    void dfs(int num, int n){
        if(n == 0){ans++; return;}
        num2times[num]--;
        for(auto y: x2y[num]){
            if(num2times[y] > 0) dfs(y, n-1);
        }
        num2times[num]++;
    }
};