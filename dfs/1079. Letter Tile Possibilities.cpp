class Solution {
public:
    int numTilePossibilities(string tiles) {
        vector<int> c2t(26, 0);
        for(auto c: tiles) c2t[c-'A']++;
        int ans = 0;
        backtracking(c2t, ans, "");
        // queue<pair<string, unordered_map<char, int>>> q;
        // q.push({"", c2t});
        // while(q.empty() == false){
        //     auto p = q.front(); q.pop();
        //     string str = p.first;
        //     unordered_map<char, int> m = p.second;
        //     ans++;
        //     for(auto )
        // }
        return ans;
    }
    
private:
    void backtracking(vector<int> c2t, int &ans, string str){
        // cout<<str<<endl;
        // if(count(c2t.begin(), c2t.end(), 0) == 26) return;
        
        for(int i = 0; i < c2t.size(); i++) if(c2t[i]){
            ans++;
            vector<int> next = c2t;
            char c = i+'A';
            int t = c2t[i];
            next[c-'A']--;
            backtracking(next, ans, str+c);
        }
    }
};