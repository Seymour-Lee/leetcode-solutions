class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q;
        vector<int> live = {0, 0};
        vector<int> bans = {0, 0};
        for(auto c: senate){
            int cur = c == 'R'? 1: 0;
            live[cur]++;
            q.push(cur);
        }
        while(live[0] > 0 && live[1] > 0){
            int cur = q.front(); q.pop();
            if(bans[cur] > 0){
                bans[cur]--;
                live[cur]--;
            }
            else{
                bans[cur^1]++;
                q.push(cur);
            }
        }
        return live[0] > 0? "Dire": "Radiant";
    }
};