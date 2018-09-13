class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> b;
        for(auto e: bank) b.insert(e);
        if(b.size() == 0 || b.find(end) == b.end()) return -1;
        if(start == end) return 0;
        int ans = 0;
        queue<string> q;
        q.push(start);
        vector<char> gene = {'A', 'C', 'G', 'T'};
        while(q.empty() == false){
            ans++;
            int size = q.size();
            while(size--){
                string cur = q.front(); q.pop();
                for(int i = 0; i < cur.size(); i++){
                    int ch = cur[i];
                    for(auto c: gene){
                        if(c == ch) continue;
                        cur[i] = c;
                        if(cur == end) return ans;
                        if(b.find(cur) != b.end()){
                            q.push(cur);
                        }
                    }
                    cur[i] = ch;
                }
            }
        }
        return -1;
    }
};