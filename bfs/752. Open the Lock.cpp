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

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> v(deadends.begin(), deadends.end());
        if(v.find(target) != v.end() || v.find("0000") != v.end()) return -1;
        queue<string> q;
        q.push("0000");
        v.insert("0000");
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            while(size--){
                auto node = q.front(); q.pop();
                if(node == target) return ans;
                for(auto &c: node){
                    char ori = c;
                    c = '0' + (ori-'0'+1)%10;
                    if(v.find(node) == v.end()) q.push(node), v.insert(node);
                    c = '0' + (ori-'0'-1+10)%10;
                    if(v.find(node) == v.end()) q.push(node), v.insert(node);
                    c = ori;
                }
            }
            ans++;
        }
        return -1;
    }
};