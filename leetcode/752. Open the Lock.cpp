class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string> dead(deadends.begin(), deadends.end());
        string start = "0000";
        if(start == target) return 0;
        if(dead.find(start) != dead.end()) return -1;
        set<string> seen{start};
        queue<string> q;
        q.push(start);
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            ans++;
            while(size--){
                string str = q.front();
                for(auto &c: str){
                    char cur = c;
                    for(int i = -1; i <= 1; i+=2){
                        c = ((c + i + 10 - '0') % 10) + '0';
                        if(str == target) return ans;
                        if(seen.find(str) == seen.end() && dead.find(str) == dead.end()){
                            q.push(str);
                            seen.insert(str);
                        }
                        c = cur;
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};