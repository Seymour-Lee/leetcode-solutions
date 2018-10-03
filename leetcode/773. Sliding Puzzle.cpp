class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int ans = 0;
        string target = "123450";
        string start = "";
        for(auto row: board) for(auto e: row) start += string(1, '0'+e);
        queue<string> qstates;
        set<string> seen;
        qstates.push(start);
        seen.insert(start);
        while(qstates.empty() == false){
            int size = qstates.size();
            while(size--){
                string front = qstates.front(); qstates.pop();
                if(front == target) return ans;
                auto nextStates = getNextStates(front);
                for(auto state: nextStates){
                    if(seen.find(state) == seen.end()){
                        seen.insert(state);
                        qstates.push(state);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
    
private:
    vector<string> getNextStates(string cur){
        vector<int> dir = {0, 1, 0, -1, 0};
        vector<string> nexts;
        auto pos = cur.find('0');
        for (int k = 0; k < 4; ++k) {
            int ni = pos/3 + dir[k];
            int nj = pos%3 + dir[k+1];
            if (ni < 0 || nj < 0 || ni >= 2 || nj >= 3)
                continue;
            swap(cur[pos], cur[ni*3+nj]);
            nexts.push_back(cur);
            swap(cur[pos], cur[ni*3+nj]);
        }
        return nexts;
    }
};