class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        map<int, set<int>> g;
        map<int, int> indegree;
        for(auto seq: seqs){
            if(seq.size() == 1){
                if(g.find(seq[0]) == g.end()){
                    g[seq[0]] = set<int>();
                    indegree[seq[0]] = 0;
                }
            }
            else{
                for(int i = 0; i < (int)seq.size()-1; i++){
                    if(g.find(seq[i]) == g.end()){
                        g[seq[i]] = set<int>();
                        indegree[seq[i]] = 0;
                    }
                    if(g.find(seq[i+1]) == g.end()){
                        g[seq[i+1]] = set<int>();
                        indegree[seq[i+1]] = 0;
                    }
                    if(g[seq[i]].find(seq[i+1]) == g[seq[i]].end()){
                        g[seq[i]].insert(seq[i+1]);
                        indegree[seq[i+1]]++;
                    }
                }
            }
        }

        queue<int> q;
        for(auto node: indegree) if(node.second == 0) q.push(node.first);

        int node = 0;
        while(q.empty() == false){
            if(q.size() > 1) return false;
            int cur = q.front(); q.pop();
            if(node == org.size() || cur != org[node++]) return false;
            for(auto next: g[cur]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        
        return node == org.size() && node == g.size();
    }
};