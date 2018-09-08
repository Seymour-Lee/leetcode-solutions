class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        for(auto pre: prerequisites){
            g[pre.second].push_back(pre.first);
            indegree[pre.first]++;
        }
        queue<int> q;
        for(int i = 0; i < indegree.size(); i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(q.empty() == false){
            int node = q.front(); q.pop();
            ans.push_back(node);
            for(auto v: g[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return ans.size() == numCourses? ans: vector<int>();
    }
};