class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        string ans = "";
        p = vector<int>(s.size(), -1);
        for(auto &pp: pairs){
            // cout<<p[0]<<" "<<p[1]<<endl;
            u(pp[0], pp[1]);
        }
        // unordered_map<int, priority_queue<char, vector<char>, greater<char>>> p2c;
        unordered_map<int, vector<int>> p2c;
        for(int i = 0; i < p.size(); i++){
            int pi = f(i);
            // u(i, pi);
            char c = s[i];
            if(p2c.find(pi) == p2c.end()) p2c[pi] = vector<int>(26, 0);
            p2c[pi][c-'a']++;
        }
        for(auto &pp: p2c) reverse(pp.second.begin(), pp.second.end());
        for(int i = 0; i < s.size(); i++){
            int pi = f(i);
            while(p2c.size() && p2c[pi].back() == 0) p2c[pi].pop_back();
            ans += (26-p2c[pi].size())+'a';
            p2c[pi].back()--;
        }
        return ans;
    }
    
private:    
    vector<int> p;
    
    int f(int x){
        if(p[x] == -1) return x;
        return p[x] = f(p[x]);
    }
    
    void u(int x, int y){
        int xp = f(x);
        int yp = f(y);
        if(xp != yp) p[xp] = yp;
    }
};