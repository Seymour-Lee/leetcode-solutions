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

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string target = "123450";
        string init = "";
        for(auto r: board) for(auto e: r) init += to_string(e);
        queue<string> q;
        q.push(init);
        unordered_set<string> v;
        int ans = 0;
        while(q.empty() == false){
            int size = q.size();
            // cout<<size<<endl;
            while(size--){
                auto node = q.front(); q.pop();
                // cout<<node<<endl;
                if(node == target) return ans;
                auto strs = next(node);
                for(auto str: strs) if(v.find(str) == v.end()){
                    q.push(str);
                    v.insert(str);
                }
            }
            ans++;
        }
        return -1;
    }
    
private:
    vector<string> next(string &prev){
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<char>> g(2, vector<char>(3));
        int i, j;
        for(int k = 0; k < prev.size(); k++){
            if(prev[k] == '0') i = k/3, j = k%3;
            g[k/3][k%3] = prev[k];
        }
        vector<string> ans;
        for(auto dir: dirs){
            int ii = i+dir[0], jj = j+dir[1];
            if(0 <= ii && ii < 2 && 0 <= jj && jj < 3){
                swap(g[ii][jj], g[i][j]);
                string str = "";
                for(auto r: g) for(auto e: r) str += e;
                ans.push_back(str);
                swap(g[ii][jj], g[i][j]);
            }
        }
        return ans;
    }
};